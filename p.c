#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_process_status(int pid) {
    char path[40], line[100];
    sprintf(path, "/proc/%d/status/", pid); 

    FILE *fp = fopen(path, "r"); 
    if (fp == NULL) {
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "State:", 6) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]); 
        return 1;
    }

    int pid = atoi(argv[1]);
    if (check_process_status(pid)) {
        printf("Process %d is running.\n", pid);
    } else {
        printf("Process %d is not running or does not exist.\n", pid); 
    }
    return 0;
}