#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r"); 
    if (!fp) {
        perror("Cannot open file.");
        return 1;
    }

    int total_lines = 0;
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            total_lines++;
        }
    }

    printf("File %s has %d total lines.\n", argv[1], total_lines);

    return 0;
}