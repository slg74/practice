#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse_string(char str[]);
bool is_palindrome(char str[]);

void reverse_string(char str[]) {
    int i, j;
    char temp;

    for (i=0, j=strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j]; 
        str[j] = temp;
    }
}

bool is_palindrome_from_int(int n) {
    char str[20];
    n = sprintf(str, "%d", n); 

    int len = strlen(str) - 1; 
    int i = 0, j = len;
    while (i < len / 2) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}

bool is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    char reversed[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';

    strcpy(reversed, str);
    reverse_string(reversed);
    printf("Reversed: %s\n", reversed);
    
    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    int n = 2112;
    if (is_palindrome_from_int(n)) {
        printf("%d is a palindrome.\n", n);
    } else {
        printf("%d is not a palindrome.\n", n);
    }

    return 0;
}