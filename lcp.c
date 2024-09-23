#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    int i, j;
    int min_len = strlen(strs[0]);
    
    // Find the minimum length string
    for (i = 1; i < strsSize; i++) {
        int len = strlen(strs[i]);
        if (len < min_len) min_len = len;
    }
    
    // Allocate memory for the result
    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    
    // Compare characters
    for (i = 0; i < min_len; i++) {
        char c = strs[0][i];
        for (j = 1; j < strsSize; j++) {
            if (strs[j][i] != c) {
                result[i] = '\0';
                return result;
            }
        }
        result[i] = c;
    }
    
    result[i] = '\0';
    return result;
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    
    char* result = longestCommonPrefix(strs, strsSize);
    printf("Longest common prefix: %s\n", result);
    
    free(result);
    return 0;
}
