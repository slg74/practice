#include <stdio.h>
#include <string.h>
#include <ctype.h>

long hex_to_dec(const char *hex) {
    long decimal = 0;
    int len = strlen(hex);
    
    for (int i = 0; i < len; i++) {
        char c = tolower(hex[i]);
        if (c >= '0' && c <= '9') {
            decimal = decimal * 16 + (c - '0');
        } else if (c >= 'a' && c <= 'f') {
            decimal = decimal * 16 + (c - 'a' + 10);
        } else {
            // Invalid character in hex string
            return -1;
        }
    }
    
    return decimal;
}


int main() {

    int a = 0x1245A78F;
    const char *a_hex = "1245a78f";

    int* ptr = &a;


    printf("Value of a is %X\n", a);
    printf("Address of a is %p\n", &a);
    printf("Pointer value is %p\n", ptr);

    printf("%ld\n", hex_to_dec(a_hex));

    return 0;
}