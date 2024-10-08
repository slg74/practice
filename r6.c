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

    return 0;
}