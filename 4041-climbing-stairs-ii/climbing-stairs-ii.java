class Solution {
    public int climbStairs(int n, int[] costs) {
        
        int[] dp = new int[n+1];
        
        for(int i = 1; i <= n; i++){
            dp[i] = Integer.MAX_VALUE;
        }
        dp[0] = 0;

        for(int i = 1; i <= n; i++){

            int sec = i - 2 < 0? Integer.MAX_VALUE - 4: dp[i - 2];
            int third = i - 3 < 0? Integer.MAX_VALUE - 9: dp[i - 3];

            dp[i] = costs[i - 1] + Math.min(dp[i - 1]+1, Math.min(sec + 4, third + 9));
            
        }

        return dp[n];
    
    
    }
}