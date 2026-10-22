class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;

        if (n == 0) {
            return -1;
        }

        int res = Integer.MAX_VALUE;
        int[] target = new int[n];

        for (int i = 0; i < n; i++) {
            target[i] = i;
        }

        int k = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                k = i;
                break;
            }
        }

        if (k == -1) {
            return -1;
        }

        int[] rotated = new int[n];

        for (int i = 0; i < n; i++) {
            rotated[i] = nums[(k + i) % n];
        }

        if (Arrays.equals(rotated, target)) {
            res = Math.min(res, Math.min(k, n - k + 2));
        }

        int[] revNums = new int[n];

        for (int i = 0; i < n; i++) {
            revNums[i] = nums[n - 1 - i];
        }

        int kRev = n - 1 - k;

        for (int i = 0; i < n; i++) {
            rotated[i] = revNums[(kRev + i) % n];
        }

        if (Arrays.equals(rotated, target)) {
            res = Math.min(
                res,
                Math.min(kRev + 1, n - kRev + 1)
            );
        }

        return res == Integer.MAX_VALUE ? -1 : res;
    }
}