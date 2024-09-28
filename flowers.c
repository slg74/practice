#include <stdbool.h>
#include <stdio.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
            bool emptyRight = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);
            
            if (emptyLeft && emptyRight) {
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count >= n;
}

int main() {
    int flowerbed[] = {1, 0, 0, 0, 1};
    int n = 1;
    int flowerbedSize = sizeof(flowerbed) / sizeof(flowerbed[0]);
    
    bool result = canPlaceFlowers(flowerbed, flowerbedSize, n);
    printf("Can place %d flowers: %s\n", n, result ? "true" : "false");
    
    return 0;
}
