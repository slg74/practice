#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

// gcc -o e29 e29.c -lgmp && ./e29 

int main() {
    mpz_t result;
    mpz_t *terms = malloc(10000 * sizeof(mpz_t));
    int index = 0;
    
    for (int i = 0; i < 10000; i++) {
        mpz_init(terms[i]);
    }
    mpz_init(result);
    
    // Generate all terms using GMP
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            mpz_ui_pow_ui(result, a, b);
            mpz_set(terms[index], result);
            index++;
        }
    }
    
    // Sort and count unique terms
    int unique_count = 1;
    for (int i = 1; i < index; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (mpz_cmp(terms[i], terms[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) unique_count++;
    }
    
    printf("%d\n", unique_count);
    
    // Cleanup
    for (int i = 0; i < 10000; i++) {
        mpz_clear(terms[i]);
    }
    mpz_clear(result);
    free(terms);
    
    return 0;
}
