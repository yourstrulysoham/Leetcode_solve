class Solution {

    public int reverseDegree(String s) {

        int result = 0;

        char[] chars = s.toCharArray();

        for (int i = 0; i < chars.length; i++) {

            int charVal = 26 - (chars[i] - 'a');

            result += charVal * (i + 1);
        }

        return result;
    }
}