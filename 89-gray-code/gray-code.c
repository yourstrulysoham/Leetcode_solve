/**
 * Note: The returned array must be malloced,
 */
int* grayCode(int n, int* retSize) {
    // Calculate the number of Gray Code values
    *retSize = 1 << n;

    // Allocate memory for the result array
    int* res = malloc(*retSize * sizeof(int));

    // Check if memory allocation failed
    if (res == NULL)
    {
        *retSize = 0;
        return NULL;
    }

    // Generate Gray Codes using XOR and right shift
    for (int i = 0; i < *retSize; ++i)
    {
        res[i] = i ^ (i >> 1);
    }

    // Return the generated sequence
    return res;
}