
def count_word_frequency(words):
    seen = {}
    for word in words:
        if word in seen:
            seen[word] += 1
        else:
            seen[word] = 1

    return seen


words = ['apple', 'orange', 'banana', 'apple', 'orange', 'apple'] 

print(count_word_frequency(words))


def count_word_frequency(words):
    word_count = {}
    for word in words:
        word_count[word] = word_count.get(word, 0) + 1
    return word_count

print(count_word_frequency(words))



def merge_dicts(dict1, dict2):
    result = dict1.copy()
    for key, value in dict2.items():
        result[key] = result.get(key, 0) + value
    return result


dict1 = {'a': 1, 'b': 2, 'c': 3}
dict2 = {'b': 3, 'c': 4, 'd': 5}
print(merge_dicts(dict1, dict2))



letters_values = {'a': 1, 'b': 99, 'c': 3, 'a': 4, 'b': 5, 'c': 6}

    

def get_letter_values(dict):
    result = dict.copy()
    for key, value in dict.items():
        result[key] = result.get(key, 0) + value
    return result

print(get_letter_values(letters_values))
