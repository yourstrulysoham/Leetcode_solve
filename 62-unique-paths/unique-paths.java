class Solution {
    public int uniquePaths(int m, int n) {
        // ans[i][j] stores the number of unique paths to cell (i, j)
        int[][] ans = new int[m][n];

        // Base case: Only 1 way to reach any cell in the top row (always move right)
        for (int i = 0; i < n; i++) {
            ans[0][i] = 1;
        }

        // Base case: Only 1 way to reach any cell in the left column (always move down)
        for (int i = 0; i < m; i++) {
            ans[i][0] = 1;
        }

        // Fill the grid using the DP state transition formula
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }

        // Return the bottom-right corner result
        return ans[m - 1][n - 1];
    }
}