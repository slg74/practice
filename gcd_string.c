#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Check if concatenations are equal
    char* concat1 = malloc(len1 + len2 + 1);
    char* concat2 = malloc(len1 + len2 + 1);
    strcpy(concat1, str1);
    strcat(concat1, str2);
    strcpy(concat2, str2);
    strcat(concat2, str1);
    
    if (strcmp(concat1, concat2) != 0) {
        free(concat1);
        free(concat2);
        return "";
    }
    
    free(concat1);
    free(concat2);
    
    // Find GCD of lengths
    int gcd = len1;
    int temp = len2;
    while (temp != 0) {
        int t = temp;
        temp = gcd % temp;
        gcd = t;
    }
    
    // Extract and return the GCD string
    char* result = malloc(gcd + 1);
    strncpy(result, str1, gcd);
    result[gcd] = '\0';
    
    return result;
}

int main() {
    char str1[] = "ABCABCABCABC";
    char str2[] = "ABCABC";
    
    char* result = gcdOfStrings(str1, str2);
    printf("Largest string that divides both: %s\n", result);
    
    free(result);
    return 0;
}
