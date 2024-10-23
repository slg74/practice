
def isValidSudoku(board):
    # Initialize sets to keep track of numbers in rows, columns and boxes
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]
    
    # Iterate through each cell in the 9x9 board
    for i in range(9):
        for j in range(9):
            current = board[i][j]
            
            # Skip empty cells
            if current == ".":
                continue
                
            # Calculate which 3x3 box we're in
            box_index = (i // 3) * 3 + j // 3
            
            # Check if current number already exists in row, column or box
            if (current in rows[i] or 
                current in cols[j] or 
                current in boxes[box_index]):
                return False
            
            # Add current number to respective sets
            rows[i].add(current)
            cols[j].add(current)
            boxes[box_index].add(current)
    
    return True


# Example valid board
board = [
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]

# Example invalid board - has duplicate 5 in first row
invalid_board = [
    ["5","3",".",".","7",".",".",".","5"],  # Duplicate 5 in row
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]


result = isValidSudoku(board)  
print(result)
result = isValidSudoku(invalid_board)  
print(result)

