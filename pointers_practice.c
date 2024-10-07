#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {

    printf("\n=== pointers ===\n");

    char a = 'A';
    char *ptr = &a;

    printf("1 | %c, %c, %llu, %p\n", a, *ptr, (uint64_t)ptr, ptr);

    char b = 'B';
    ptr = &b;
    printf("2 | %c, %c, %llu, %p\n", b, *ptr, (uint64_t)ptr, ptr);

    *ptr = 'C';
    printf("3 | %c, %c, %llu, %p\n", b, *ptr, (uint64_t)ptr, ptr);

    (*ptr)++;
    printf("4 | %c, %c, %llu, %p\n", b, *ptr, (uint64_t)ptr, ptr);


    printf("\n=== pointers ===\n");


    return EXIT_SUCCESS;
}