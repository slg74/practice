#include <stdio.h>
#include <stdlib.h>

int minDisks(int* fileSizes, int numFiles, int diskCapacity) {
    int disks = 1;
    int currentDiskSpace = diskCapacity;

    for (int i = 0; i < numFiles; i++) {
        if (fileSizes[i] > currentDiskSpace) {
            disks++;
            currentDiskSpace = diskCapacity;
        }
        currentDiskSpace -= fileSizes[i];
    }

    return disks;
}

int main() {
    int fileSizes[] = {100, 200, 300, 400, 500};
    int numFiles = sizeof(fileSizes) / sizeof(fileSizes[0]);
    int diskCapacity = 700;

    int result = minDisks(fileSizes, numFiles, diskCapacity);
    printf("Minimum number of disks required: %d\n", result);

    return 0;
}
