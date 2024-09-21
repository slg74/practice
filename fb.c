#include <stdio.h>

int main() {

    int i;

    char* out_fizz = "Fizz";
    char* out_buzz = "Buzz";
    char* out_both = "FizzBuzz"; 

    for (i=0; i < 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            printf("%s\n", out_both);
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