/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes);

void pushInterval(int** ans, int* retSize, int** retColS, int lB, int hB);

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int **ans = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));

    *returnSize = 0;

    for (int i = 0; i < intervalsSize; i++) {
        int lowBound = intervals[i][0];
        int highBound = intervals[i][1];

        if (newInterval[1] < lowBound) {
            pushInterval(ans, returnSize, returnColumnSizes, newInterval[0], newInterval[1]);
            newInterval[0] = lowBound;
            newInterval[1] = highBound;
        } else if (newInterval[0] > highBound) {
            pushInterval(ans, returnSize, returnColumnSizes, lowBound, highBound);
        } else {
            if (lowBound < newInterval[0]) {
                newInterval[0] = lowBound;
            }
            if (highBound > newInterval[1]) {
                newInterval[1] = highBound;
            }
        }
    }

    pushInterval(ans, returnSize, returnColumnSizes, newInterval[0], newInterval[1]);
    return ans;
}

void pushInterval(int** ans, int* retSize, int** retColS, int lB, int hB) {
    ans[*retSize] = malloc(2 * sizeof(int));
    ans[*retSize][0] = lB;
    ans[*retSize][1] = hB;
    (*retColS)[*retSize] = 2;
    (*retSize)++;
}