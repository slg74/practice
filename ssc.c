#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find_all_occurrences(char str[], char c, int indexes[]) {

    int found = 0;
    char *p_str = str;

    while (p_str) {
        p_str = strchr(p_str, c);
        if (p_str) {
            indexes[found++] = p_str++ - str;
        }
    }
    return found;
}

void print_occurrences(char str[], int occurrence_indexes[], int found) {

    char pattern[strlen(str) + 1];
    memset(pattern, ' ', sizeof(pattern));

    for (int i = 0; i < found; i++) {
        pattern[occurrence_indexes[i]] = '^';
    }
    pattern[sizeof(pattern) - 1] = '\0'; 
    printf("%s\n", str);
    printf("%s\n", pattern); 
}

int main() {

    char str[] = "This is a sample string";

    int occurrence_indexes[sizeof(str)]; 

    int found = find_all_occurrences(str, 's', occurrence_indexes); 

    print_occurrences(str, occurrence_indexes, found);

    return EXIT_SUCCESS;
}