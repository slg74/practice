#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Cannot open file.");
        return 1;
    }

    int total_lines = 0;
    int ch; // fgetc() returns int
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            total_lines++;
        }
    }
    printf("File: %s has %d total lines.\n", argv[1], total_lines);
    return 0;
}