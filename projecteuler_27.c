#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(abs(n)); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int count_consecutive_primes(int a, int b) {
    int n = 0;
    while (true) {
        int result = n*n + a*n + b;
        if (!is_prime(result)) return n;
        n++;
    }
}

int main() {
    int max_primes = 0;
    int best_a = 0;
    int best_b = 0;
    
    // Create array for prime b values
    int b_primes[2001];
    int b_count = 0;
    
    // Find prime b values
    for (int b = -1000; b <= 1000; b++) {
        if (is_prime(abs(b))) {
            b_primes[b_count++] = b;
        }
    }
    
    // Main calculation loop
    for (int a = -999; a < 1000; a++) {
        for (int i = 0; i < b_count; i++) {
            int b = b_primes[i];
            
            // Check if second number is prime (when n=1)
            if (!is_prime(1 + a + b)) continue;
            
            int count = count_consecutive_primes(a, b);
            if (count > max_primes) {
                max_primes = count;
                best_a = a;
                best_b = b;
            }
        }
    }
    
    printf("a = %d, b = %d\n", best_a, best_b);
    printf("Number of primes = %d\n", max_primes);
    printf("Product = %d\n", best_a * best_b);
    
    return 0;
}
