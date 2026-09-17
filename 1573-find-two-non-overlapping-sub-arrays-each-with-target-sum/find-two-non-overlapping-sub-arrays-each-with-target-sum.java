class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int[] best = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            best[i] = n + 1;
        }

        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);

        int prefixSum = 0;
        int res = n + 1;

        for (int i = 1; i <= n; i++) {
            prefixSum += arr[i - 1];
            best[i] = best[i - 1];

            if (map.containsKey(prefixSum - target)) {
                int left = map.get(prefixSum - target);
                int length = i - left;

                if (best[left] != n + 1) {
                    res = Math.min(res, best[left] + length);
                }

                best[i] = Math.min(best[i], length);
            }

            map.put(prefixSum, i);
        }

        return res == n + 1 ? -1 : res;
    }
}