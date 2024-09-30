#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r"); 
    if (!file) {
        perror("Cannot open file.");
        return 1;
    }

    int total = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            total++;
        }
    }
    printf("File %s has %d lines.\n", argv[1], total);
    return 0;
}