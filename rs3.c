#include <stdio.h>
#include <string.h>

void reverse_string(char str[]) {
    int i, j;
    char temp;

    for (i=0, j=strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';

    reverse_string(str);
    printf("Reversed string: %s\n", str);

    return 0;
}