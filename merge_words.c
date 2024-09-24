#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mergeAlternately(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2); 
    int merged_len = len1 + len2;

    char* merged = (char *)malloc((merged_len + 1) * sizeof(char));

    int i = 0;
    int j = 0; 
    int k = 0;

    while (i < len1 || j < len2) {
        if (i < len1) {
            merged[k++] = word1[i++];
        }
        if (j < len2) {
            merged[k++] = word2[j++];
        }
    }
    merged[k] = '\0';  // end the merged string

    return merged;
}

int main() {
    char word1[] = "abcdf";
    char word2[] = "pqrzx";
    char* result = mergeAlternately(word1, word2);
    printf("Merged string: %s\n", result);
    free(result);
    return 0;
}
