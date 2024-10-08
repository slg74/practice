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

    //char str[100];

    char str[] = "This is a string";
    str[strlen(str)-1] = '\0';
    printf("Forward: %s\n", str);

    reverse_string(str);
    printf("Reversed: %s\n", str);

    return 0;
}