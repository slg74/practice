#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> parentheses;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            parentheses.push(c);
        } else {
            if (parentheses.empty()) return false;
            
            if (c == ')' && parentheses.top() != '(') return false;
            if (c == ']' && parentheses.top() != '[') return false;
            if (c == '}' && parentheses.top() != '{') return false;
            
            parentheses.pop();
        }
    }
    
    return parentheses.empty();
}

int main() {
    string test1 = "()[]{}";
    string test2 = "([)]";
    string test3 = "{[]}";
    
    cout << "Test 1: " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    
    return 0;
}
