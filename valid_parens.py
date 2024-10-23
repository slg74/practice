def is_valid(s: str) -> bool:
    stack = []
    bracket_map = {")": "(", "}": "{", "]": "["}

    for char in s:
        if char in bracket_map:
            if not stack or stack[-1] != bracket_map[char]:
                return False
            stack.pop()
        else:
            # not a closing bracket, so append to stack
            stack.append(char)

    if len(stack) == 0:
        return True
    return False

# Example usage
test_cases = ["()", "()[]{}", "(]", "([)]", "{[]}"]
for case in test_cases:
    print(f"'{case}' is valid: {is_valid(case)}")
