#include <stdio.h>
#include <stdlib.h>

#define LEN 5


void print_array(int ar[]) {
    for (int i=0; i < LEN; i++) {
        printf(" %d ", ar[i]);
    }
    printf("\n");
}

void init_array(int ar[], int value) {
    for (int i=0; i < LEN; i++) {
        ar[i] = value;
    }
}

int main() {

    int ar[LEN];

    init_array(ar, 777);

    print_array(ar); 

    int ar2[LEN] = {[1] = 1, [3] = 1};

    print_array(ar2);

    return EXIT_SUCCESS;
}