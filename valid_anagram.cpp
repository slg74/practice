#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::string sorted_s = s;
        std::string sorted_t = t;

        std::sort(sorted_s.begin(), sorted_s.end());
        std::sort(sorted_t.begin(), sorted_t.end());

        return sorted_s == sorted_t;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    std::string s1 = "anagram";
    std::string t1 = "nagaram";
    
    std::string s2 = "rat";
    std::string t2 = "car";
    
    // Print results
    std::cout << "Test Case 1: " << std::boolalpha 
              << solution.isAnagram(s1, t1) << std::endl;  // Should print true
    
    std::cout << "Test Case 2: " << std::boolalpha 
              << solution.isAnagram(s2, t2) << std::endl;  // Should print false
    
    return 0;
}
