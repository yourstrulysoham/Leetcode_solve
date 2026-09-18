class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }
        List<String> result = new ArrayList<>();
        List<int[]> intervals = new ArrayList<>();
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1)
                continue;
            int start = first[c];
            int end = last[c];
            boolean valid = true;
            for (int j = start; j <= end; j++) {
                int x = s.charAt(j) - 'a';
                if (first[x] < start) {
                    valid = false;
                    break;
                }
                end = Math.max(end, last[x]);
            }
            if (valid) {
                result.add(s.substring(start, end + 1));
                intervals.add(new int[] { start, end });
            }
        }
        intervals.sort((a, b) -> a[1] - b[1]);
        List<String> ans = new ArrayList<>();
        int prevEnd = -1;
        for (int[] interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if (start > prevEnd) {
                ans.add(s.substring(start, end + 1));
                prevEnd = end;
            }
        }
        return ans;
    }
}