#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);
    for (int i = 1; i <= len / 2; i++) {
        if (len % i == 0) {
            bool match = true;
            for (int j = i; j < len; j++) {
                if (s[j] != s[j % i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char s1[] = "abab";
    char s2[] = "aba";
    char s3[] = "abcabcabc";

    printf("%s: %s\n", s1, repeatedSubstringPattern(s1) ? "true" : "false");
    printf("%s: %s\n", s2, repeatedSubstringPattern(s2) ? "true" : "false");
    printf("%s: %s\n", s3, repeatedSubstringPattern(s3) ? "true" : "false");

    return 0;
}