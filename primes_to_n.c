#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]); 
        return 1;
    }

    int n = atoi(argv[1]); 

    for (int i = 0; i < n; i++) {
        if (is_prime(i)) {
            printf(" %d ", i);
        }
    }
    printf("\n"); 

    return EXIT_SUCCESS;
}