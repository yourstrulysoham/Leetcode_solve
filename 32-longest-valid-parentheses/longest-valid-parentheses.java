class Solution {
    public int longestValidParentheses(String s) {
        int ans = 0;
        int open=0,close=0;
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)=='(') open++;
            else close++;
            if(open == close)
                ans = Math.max(ans,open+close);
            else if(close > open)
                open = close = 0;
        }
        open=close=0;
        for(int i=s.length()-1;i>=0;i--) {
            if(s.charAt(i)=='(') open++;
            else close++;
            if(open == close)
                ans = Math.max(ans,open+close);
            else if(close < open)
                open = close = 0;
        }
        return ans;
    }
}