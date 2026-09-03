class Solution {
    public boolean uniformArray(int[] nums1) {
        int minOdd = Integer.MAX_VALUE;

        // Find the smallest odd number.
        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = Math.min(minOdd, x);
            }
        }

        // No odd numbers means all numbers are already even.
        if (minOdd == Integer.MAX_VALUE) {
            return true;
        }

        // Every even number must have a smaller odd number
        // available to subtract.
        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd) {
                return false;
            }
        }

        return true;
    }
}