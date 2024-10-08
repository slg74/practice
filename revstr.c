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
    char str[] = "This is a string";

    reverse_string(str);
    printf("%s\n", str);

    return 0;
}