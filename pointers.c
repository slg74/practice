#include <stdio.h>

void swap(int *px, int *py); 

int main() {

    int x = 5;
    int y = 7;

    int *px = &x;
    int *py = &y;

    printf("%d %d %d %d %p %p\n", *px, *py, x, y, &x, &y);

    px = &y;
    py = &x; 

    printf("%d %d %d %d %p %p\n", *px, *py, x, y, &x, &y);

    int i = 10;
    int j = 20;

    printf("%d %d\n", i, j);
    printf("%d %d %p %p\n", i, j, &i, &j);

    printf("Before swap: i = %d, j = %d\n", i, j);
    swap(&i, &j);
    printf("After swap: i = %d, j = %d\n", i, j);

    printf("%d %d\n", i, j);
    printf("%d %d %p %p\n", i, j, &i, &j);

    return 0;
}

void swap(int *px, int *py) {
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}