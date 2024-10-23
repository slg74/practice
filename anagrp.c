#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_STRS 10000


int char_compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char*** group_anagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char*** groups = (char***)malloc(strsSize * sizeof(char**));
    int* groupSizes = (int*)calloc(strsSize, sizeof(int));
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char sorted[MAX_STR_LEN];
        strcpy(sorted, strs[i]);
        qsort(sorted, strlen(sorted), sizeof(char), char_compare);

        int found = 0;
        for (int j = 0; j < groupCount; j++) {
            char firstSorted[MAX_STR_LEN];
            strcpy(firstSorted, groups[j][0]);
            qsort(firstSorted, strlen(firstSorted), sizeof(char), char_compare);

            if (strcmp(sorted, firstSorted) == 0) {
                groups[j] = (char**)realloc(groups[j], (groupSizes[j] + 1) * sizeof(char*));
                groups[j][groupSizes[j]] = strdup(strs[i]);
                groupSizes[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            groups[groupCount] = (char**)malloc(sizeof(char*));
            groups[groupCount][0] = strdup(strs[i]);
            groupSizes[groupCount] = 1;
            groupCount++;
        }
    }

    *returnSize = groupCount;
    *returnColumnSizes = groupSizes;
    return groups;
}

int main() {
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;

    char*** result = group_anagrams(strs, strsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", result[i][j]);  // This is correct as %s for strings
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            free(result[i][j]);
        }
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}