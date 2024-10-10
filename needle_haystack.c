#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(const char* haystack, const char* needle) {
    if (!*needle) return 0;  // Empty needle

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    for (int i = 0; i <= haystack_len - needle_len; i++) {
        printf("haystack + i: %s\tneedle: %s\tneedle_len: %d\n", haystack + i, needle, needle_len);
        if (strncmp(haystack + i, needle, needle_len) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    const char* haystack = "codeleetcodeleet";
    const char* needle = "del";

    int result = strStr(haystack, needle);
    printf("First occurrence at index: %d\n", result);

/*
    const char* first = "Hello this is a test";
    const char* second = "Hello from outer space";

    int res = strncmp(first, second, 5); 
    if (res == 0) {
        printf("First 5 chars of first and second are equal\n"); 
    } else {
        printf("First 5 chars of first and second are not equal\n"); 
    }

    int res2 = strncmp(first, second, 10);
    if (res2== 0) {
        printf("First 10 chars of first and second are equal\n"); 
    } else {
        printf("First 10 chars of first and second are not equal\n"); 
    }
*/
    return EXIT_SUCCESS;
}
