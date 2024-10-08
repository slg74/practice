#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {
    if (s == NULL || *s == '\0') return "";
    
    int start = 0, max_len = 1;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        // Check for odd length palindromes
        int left = i, right = i;
        while (left >= 0 && right < len && s[left] == s[right]) {
            if (right - left + 1 > max_len) {
                start = left;
                max_len = right - left + 1;
            }
            left--;
            right++;
        }
        
        // Check for even length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < len && s[left] == s[right]) {
            if (right - left + 1 > max_len) {
                start = left;
                max_len = right - left + 1;
            }
            left--;
            right++;
        }
    }
    
    static char result[1001];  // Assuming max string length is 1000
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';
    return result;
}

int main() {
    char s[1001];
    printf("Enter a string: ");
    scanf("%1000s", s);
    
    char* longest = longestPalindrome(s);
    printf("Longest palindromic substring: %s\n", longest);
    
    return 0;
}
