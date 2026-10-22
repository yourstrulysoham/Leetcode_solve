/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    *returnSize = digitsSize;
    int *ans = (int *)malloc(*returnSize * sizeof(int));
    int consecutiveCount = 0;
    int consecutiveCountTemp = 0;

    if (ans == NULL) return NULL;

    // First Check
    for (int i = digitsSize - 1; i > -1; i--) {

        if (i == digitsSize - 1 && digits[i] != 9) ans[i] = digits[i] + 1;
        if (i != digitsSize - 1) ans[i] = digits[i];
        if (digits[i] == 9) consecutiveCountTemp += 1;
        if (digits[i] != 9 && consecutiveCountTemp > consecutiveCount) {
            consecutiveCount = consecutiveCountTemp;
            consecutiveCountTemp = 0; 
        }
        if (digits[i] != 9) consecutiveCountTemp = 0; 
    }

    if (consecutiveCountTemp > consecutiveCount) consecutiveCount = consecutiveCountTemp;
    if (consecutiveCount >= 1 && digits[digitsSize - 1] != 9) consecutiveCount = 0;
    if (digitsSize > 1 && consecutiveCount > 1 && digits[digitsSize - 1] == 9 && digits[digitsSize - 2] != 9) consecutiveCount = 1;

    int index = digitsSize;
    if (consecutiveCount == digitsSize) {
        *returnSize = digitsSize + 1;
        ans = (int *)realloc(ans, *returnSize * sizeof(int));
        if (ans == NULL) return NULL;
    }

    if (consecutiveCount > 0 && consecutiveCount != digitsSize) index = digitsSize - 1;
    
    // Second Check
    int count = 0;
    for (int i = *returnSize - 1; i > -1; i--) {

        if (consecutiveCount == digitsSize && i > 0) {
            ans[index--] = 0;
            ans[0] = 1;
        } 

        if (count < consecutiveCount && consecutiveCount != digitsSize && digits[index] == 9) {
            count += 1;
            ans[index--] = 0;
        }
    }

    if (consecutiveCount != 0 && count == consecutiveCount && consecutiveCount != digitsSize) {
        ans[index] += 1;
    }

    return ans;

}