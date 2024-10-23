#include <stdio.h>
#include <stdlib.h>

int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    
    for (int row = 0; row < imageSize; row++) {
        int n = imageColSize[row];
        for (int col = 0; col < (n + 1) / 2; col++) {
            // Swap and invert elements
            int temp = image[row][col];
            image[row][col] = 1 - image[row][n - 1 - col];
            image[row][n - 1 - col] = 1 - temp;
        }
    }
    
    return image;
}

int main() {
    int rows = 3;
    int cols = 3;
    int** image = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        image[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // Initialize the image
    int init[3][3] = {{1,1,0},{1,0,1},{0,0,0}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = init[i][j];
        }
    }
    
    int* colSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        colSizes[i] = cols;
    }
    
    int returnSize;
    int* returnColumnSizes;
    
    int** result = flipAndInvertImage(image, rows, colSizes, &returnSize, &returnColumnSizes);
    
    // Print the result
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(image[i]);
    }
    free(image);
    free(colSizes);
    
    return 0;
}
