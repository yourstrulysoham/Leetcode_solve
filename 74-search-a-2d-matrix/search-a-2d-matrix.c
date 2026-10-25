bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize,
                  int target) {
    int low = 0, high = (matrixSize*(*matrixColSize))-1, mid = 0, row = 0, col = 0,ms=*matrixColSize;
    while (low <= high) {
        mid = (low + high) / 2;
        row = mid / ms;
        col = mid % ms;

        if (matrix[row][col] <= target) {
            if (matrix[row][col] == target) {
                return true;
            }
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}