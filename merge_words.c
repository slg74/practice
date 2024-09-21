#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mergeAlternately(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int mergedLen = len1 + len2;
    
    char* merged = (char*)malloc((mergedLen + 1) * sizeof(char));
    int i = 0, j = 0, k = 0;
    
    while (i < len1 && j < len2) {
        merged[k++] = word1[i++];
        merged[k++] = word2[j++];
    }
    
    while (i < len1) {
        merged[k++] = word1[i++];
    }
    
    while (j < len2) {
        merged[k++] = word2[j++];
    }
    
    merged[k] = '\0';
    return merged;
}

char *mergeAlphabetically(char* word1, char* word2) {
    int len1 = strlen(word1); 
    int len2 = strlen(word2); 
    int mergedLen = len1 + len2;

    char* merged = (char *)malloc((mergedLen + 1) * sizeof(char)); 

    int i = 0;
    int j = 0; 
    int k = 0; 

    while (i < len1 && j < len2) {
        if (word1[i] <= word2[j]) {
            merged[k++] = word1[i++];
        } else {
            merged[k++] = word2[j++];
        }
    }

    while (i < len1) merged[k++] = word1[i++];
    while (j < len2) merged[k++] = word2[j++];

    merged[k] = '\0';
    return merged;
}

int main() {
    char word1[] = "abc";
    char word2[] = "pqr";
    
    char* result = mergeAlternately(word1, word2);
    printf("Merged string: %s\n", result);

    char* alphabetic_result = mergeAlphabetically(word1, word2);
    printf("Merged string: %s\n", alphabetic_result);
    
    free(result);
    free(alphabetic_result);
    
    return 0;
}
