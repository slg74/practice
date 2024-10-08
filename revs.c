#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        // Swap the characters
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        // Move pointers towards the center
        start++;
        end--;
    }
}

int main() {
    char str[100];
    
    // Input the string
    printf("Enter a string: ");
    gets(str);  // Be careful, 'gets' can cause buffer overflow, use 'fgets' in real programs
    
    // Reverse the string
    reverseString(str);
    
    // Print the reversed string
    printf("Reversed string: %s\n", str);
    
    return 0;
}
