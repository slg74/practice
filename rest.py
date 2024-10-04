from flask import Flask, request, jsonify

app = Flask(__name__)

# In-memory storage for items
items = {}
item_id_counter = 1

@app.route('/items', methods=['GET'])
def get_items():
    return jsonify(list(items.values()))

// Create
@app.route('/items', methods=['POST'])
def create_item():
    global item_id_counter
    data = request.json
    new_item = {
        'id': item_id_counter,
        'name': data['name'],
        'description': data.get('description', '')
    }
    items[item_id_counter] = new_item
    item_id_counter += 1
    return jsonify(new_item), 201

// Read
@app.route('/items/<int:item_id>', methods=['GET'])
def get_item(item_id):
    item = items.get(item_id)
    if item:
        return jsonify(item)
    return jsonify({'error': 'Item not found'}), 404

// Update
@app.route('/items/<int:item_id>', methods=['PUT'])
def update_item(item_id):
    item = items.get(item_id)
    if item:
        data = request.json
        item['name'] = data.get('name', item['name'])
        item['description'] = data.get('description', item['description'])
        return jsonify(item)
    return jsonify({'error': 'Item not found'}), 404

// Delete
@app.route('/items/<int:item_id>', methods=['DELETE'])
def delete_item(item_id):
    if item_id in items:
        del items[item_id]
        return '', 204
    return jsonify({'error': 'Item not found'}), 404

if __name__ == '__main__':
    app.run(debug=True)
