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
    printf("5 | %c, %c, %llu, %p\n", b, *ptr, (uint64_t)ptr, ptr);

    unsigned x = 'A';
    ptr = (char *)&x; 
    printf("6 | %u, %c, %llu, %p\n", x, *ptr, (uint64_t)&x, ptr);

    unsigned y = 'B';
    ptr = (char *)&y;
    printf("7 | %u, %c, %llu, %p\n", y, *ptr, (uint64_t)&y, ptr);

    *ptr = 'C';


    


    printf("\n=== pointers ===\n");


    return EXIT_SUCCESS;
}