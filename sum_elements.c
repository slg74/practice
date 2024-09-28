#include <stdio.h>

int main() {
    int ar[5] = { 1, 2, 3, 4, 5 };

    int sum = 0;
    for (int i=0; i < 5; i++) {
        sum += ar[i];
    }
    printf("The sum is %d\n", sum);

    printf("The size of ar[5] is %lu elements\n", sizeof(ar)/sizeof(int));

    return 0;
}