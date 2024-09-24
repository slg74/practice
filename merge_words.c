#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

/*int main() {
    char word1[] = "abcdf";
    char word2[] = "pqrzx";
    char* result = mergeAlternately(word1, word2);
    printf("Merged string: %s\n", result);
    free(result);
    return 0;
}*/

int main() {
    char word1[] = "abc";
    char word2[] = "pqr";
    
    clock_t start = clock();
    
    for (int i = 0; i < 1000; i++) {
        char* result = mergeAlternately(word1, word2);
        free(result);  // Free the memory to avoid leaks
    }
    
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000000;
    
    printf("Time taken to run mergeAlternately 1000 times: %.2f microseconds\n", cpu_time_used);
    
    // Run once more for verification
    char* final_result = mergeAlternately(word1, word2);
    printf("Merged string: %s\n", final_result);
    free(final_result);
    
    return 0;
}
