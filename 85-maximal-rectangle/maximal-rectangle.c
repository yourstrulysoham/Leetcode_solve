int largestRectangleArea(int *heights, int n) {
    int stack[201];
    int top = -1;
    int maxArea = 0;
    for (int i = 0; i <= n; i++) {
        int curr = (i == n) ? 0 : heights[i];
        while (top != -1 && curr < heights[stack[top]]) {
            int h = heights[stack[top--]];
            int width;
            if (top == -1){
                width = i;
                }
            else {
                width = i - stack[top] - 1;
            }
            int area = h * width;
            if (area > maxArea){
                maxArea = area;
            }
        }
        stack[++top] = i;
    }
    return maxArea;
}
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0){
        return 0;
        }
    int cols = matrixColSize[0];
    int heights[200] = {0};
    int maxArea = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1'){
                heights[j]++;
                }
            else {
                heights[j] = 0;
                }
        }
        int area = largestRectangleArea(heights, cols);
        if (area > maxArea) {
            maxArea = area;
            }
    }
    return maxArea;
}