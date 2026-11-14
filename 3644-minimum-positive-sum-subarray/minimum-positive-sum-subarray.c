int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int min_sum = INT_MAX;

    for (int size = l; size <= r; size++) {
        int total = 0;

        for (int i = 0; i < size; i++) {
            total += nums[i];
        }

        if (total > 0 && total < min_sum) {
            min_sum = total;
        }

        for (int right = size; right < numsSize; right++) {
            total = total + nums[right] - nums[right - size];

            if (total > 0 && total < min_sum) {
                min_sum = total;
            }
        }
    }

    return min_sum == INT_MAX ? -1 : min_sum;
}