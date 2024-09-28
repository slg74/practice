#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long to_gb(unsigned long val); 

void parse_meminfo() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        exit(1);
    }

    char line[256]; 
    unsigned long total_mem = 0, free_mem = 0, available_mem = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line + 9, "%lu", &total_mem);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line + 8, "%lu", &free_mem);
        } else if (strncmp(line, "MemAvailable:", 13) == 0) {
            sscanf(line + 13, "%lu", &available_mem); 
        }
    }

    fclose(fp);

    printf("Total Memory:     %lu GB\n", to_gb(total_mem)); 
    printf("Free Memory:      %lu GB\n", to_gb(free_mem)); 
    printf("Available Memory: %lu GB\n", to_gb(available_mem)); 
}

unsigned long to_gb(unsigned long val) {
    return val / (1024 * 1024); 
}

int main() {
    parse_meminfo();
    return 0;
}
