class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    
    public List<List<Integer>> combine(int n, int k) {
        List<Integer> list = new ArrayList<>();
        helper(n, k, 0, list);
        return ans;
    }

    void helper(int n, int k, int num, List<Integer> list) {
        if (k == 0) {
            // If we've picked k numbers, add the combination to answer
            ans.add(new ArrayList<>(list));
            return;
        }
        
        for (int i = num + 1; i <= n; i++) {
            list.add(i);                       // Choose the number
            helper(n, k - 1, i, list);         // Explore further
            list.remove(list.size() - 1);      // Backtrack
        }
    }
}