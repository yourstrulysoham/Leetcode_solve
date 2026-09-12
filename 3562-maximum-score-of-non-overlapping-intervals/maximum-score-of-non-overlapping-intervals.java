class Solution {
    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();
        int[][] a = new int[n][4];

        for (int i = 0; i < n; i++) {
            a[i][0] = intervals.get(i).get(0);
            a[i][1] = intervals.get(i).get(1);
            a[i][2] = intervals.get(i).get(2);
            a[i][3] = i;
        }

        Arrays.sort(a, (x, y) -> Integer.compare(x[0], y[0]));

        int[] next = new int[n];

        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (a[mid][0] > a[i][1]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            next[i] = left;
        }

        long[][] dp = new long[n + 1][5];
        long[][] code = new long[n + 1][5];

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                long skip = dp[i + 1][k];
                long skipCode = code[i + 1][k];
                long take = a[i][2] + dp[next[i]][k - 1];
                long takeCode = insert(code[next[i]][k - 1], a[i][3]);

                if (take > skip ||
                    (take == skip &&
                     Long.compareUnsigned(takeCode, skipCode) < 0)) {

                    dp[i][k] = take;
                    code[i][k] = takeCode;
                } else {
                    dp[i][k] = skip;
                    code[i][k] = skipCode;
                }
            }
        }

        return decode(code[0][4]);
    }

    private long insert(long code, int index) {
        int[] a = new int[4];

        for (int i = 0; i < 4; i++) {
            a[i] = (int) ((code >>> (48 - 16 * i)) & 0xFFFF);
        }

        int value = index + 1;
        int pos = 0;

        while (pos < 4 && a[pos] != 0 && a[pos] < value) {
            pos++;
        }

        for (int i = 3; i > pos; i--) {
            a[i] = a[i - 1];
        }

        a[pos] = value;
        long res = 0;

        for (int x : a) {
            res = (res << 16) | x;
        }

        return res;
    }

    private int[] decode(long code) {
        int count = 0;

        for (int i = 0; i < 4; i++) {
            if (((code >>> (48 - 16 * i)) & 0xFFFF) != 0) {
                count++;
            }
        }

        int[] res = new int[count];

        for (int i = 0; i < count; i++) {
            res[i] = (int) ((code >>> (48 - 16 * i)) & 0xFFFF) - 1;
        }

        return res;
    }
}