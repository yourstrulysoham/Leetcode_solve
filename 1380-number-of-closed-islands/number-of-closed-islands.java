class Solution {
    public int closedIsland(int[][] grid) {
        // Intuition: border land can never be closed, sink it first, then count what's left
        int m = grid.length;
        int n = grid[0].length;

        // Sink islands touching the border
        for (int x = 0; x < m; x++) {
            sink(grid, x, 0);
            sink(grid, x, n - 1);
        }
        for (int y = 0; y < n; y++) {
            sink(grid, 0, y);
            sink(grid, m - 1, y);
        }

        // Remaining land is always closed
        int r = 0;
        for (int x = 1; x < m - 1; x++) {
            for (int y = 1; y < n - 1; y++) {
                if (grid[x][y] == 1) continue;
                sink(grid, x, y);
                r++;
            }
        }
        return r;
    }

    private void sink(int[][] grid, int x, int y) {
        if (x < 0 || x >= grid.length) return;
        if (y < 0 || y >= grid[0].length) return;
        if (grid[x][y] == 1) return;
        grid[x][y] = 1;
        sink(grid, x + 1, y);
        sink(grid, x - 1, y);
        sink(grid, x, y + 1);
        sink(grid, x, y - 1);
    }
}