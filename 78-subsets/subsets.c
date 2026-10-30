/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

// Recursive helper for generating subsets
void recHelper(int arr[], int size, int** res, int* resSize, int* colSizes, int* temp, int tempIndex, int currIndex){
    // Save the current subset
    res[*resSize] = malloc(tempIndex * sizeof(int));
    for(int i = 0; i < tempIndex; i++) {
        res[*resSize][i] = temp[i];
    }
    colSizes[*resSize] = tempIndex;
    (*resSize)++;

    for(int i = currIndex; i < size; i++){
        temp[tempIndex] = arr[i];
        recHelper(arr, size, res, resSize, colSizes, temp, tempIndex + 1, i + 1);
    }
}

// Main function to return all subsets
int** subsets(int arr[], int size, int* returnSize, int** returnColumnSizes){
    int len = 1 << size; // Total subsets = 2^n
    int** res = malloc(len * sizeof(int*));
    int* colSizes = malloc(len * sizeof(int));
    int* temp = malloc(size * sizeof(int));
    *returnSize = 0;

    recHelper(arr, size, res, returnSize, colSizes, temp, 0, 0);

    *returnColumnSizes = colSizes;
    free(temp);
    return res;
}