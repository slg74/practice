#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_STRS 10000

typedef struct {
    char** strs;
    int size;
} AnagramGroup;

int compare(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

char* sort_string(char* str) {
    char* sorted = strdup(str);
    qsort(sorted, strlen(sorted), sizeof(char), compare);
    return sorted;
}

AnagramGroup* group_anagrams(char** strs, int strsSize, int* returnSize) {
    AnagramGroup* groups = malloc(strsSize * sizeof(AnagramGroup));
    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char* sorted = sort_string(strs[i]);
        int found = 0;

        for (int j = 0; j < groupCount; j++) {
            if (strcmp(sort_string(groups[j].strs[0]), sorted) == 0) {
                groups[j].strs = realloc(groups[j].strs, (groups[j].size + 1) * sizeof(char*));
                groups[j].strs[groups[j].size] = strdup(strs[i]);
                groups[j].size++;
                found = 1;
                break;
            }
        }

        if (!found) {
            groups[groupCount].strs = malloc(sizeof(char*));
            groups[groupCount].strs[0] = strdup(strs[i]);
            groups[groupCount].size = 1;
            groupCount++;
        }

        free(sorted);
    }

    *returnSize = groupCount;
    return groups;
}

int main() {
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize;

    AnagramGroup* result = group_anagrams(strs, strsSize, &returnSize);

    printf("Anagram groups:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < result[i].size; j++) {
            printf("%s ", result[i].strs[j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < result[i].size; j++) {
            free(result[i].strs[j]);
        }
        free(result[i].strs);
    }
    free(result);

    return 0;
}
