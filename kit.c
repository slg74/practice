#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1000

int main() {

    char buf[LEN];

    char str1[] = "this is a string";
    char str2[] = "second part of string";

    str1[strlen(str1)] = '\0';
    str2[strlen(str2)] = '\0';

    strcat(buf, str1);
    strcat(buf, " ");
    strcat(buf, str2); 

    buf[strlen(buf)] = '\0';

    printf("%s\n", buf);

    int charcount = 0;

    for (int i = 0; i < strlen(buf); i++) {
        printf("%c", buf[i]);
        charcount++;
    }

    printf("\nbuf size: %lu \nchar count: %d\n", strlen(buf), charcount);

    // test
    printf("\nbuf[999] = %c", buf[999]); 

    printf("\n");

    for (int i = 0; i < LEN; i++) {
        printf("%d | %c\n", i, buf[i]);
    }

    return EXIT_SUCCESS;
}