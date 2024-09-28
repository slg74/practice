#include <stdio.h>

int main() {

    const char* out_fizz     = "Fizz";
    const char* out_buzz     = "Buzz";
    const char* out_fizzbuzz = "FizzBuzz"; 

    for (int i=0; i < 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("%s\n", out_fizzbuzz);
        } else if (i % 3 == 0) {
            printf("%s\n", out_fizz); 
        } else if (i % 5 == 0) {
            printf("%s\n", out_buzz); 
        } else {
            printf("%d\n", i); 
        }
    }
    return 0;
}