#define MAX(a,b) (a > b ? a : b)
int lengthOfLongestSubstring(char* s) {
    int* hash = (int*)malloc(128 * sizeof(int));
    int maxLen = 0 , i = 0;
    for(int j = 0; s[j] != '\0'; j++) {
        if(hash[s[j]] >= i) {
            i = hash[s[j]] + 1;
        }
        hash[s[j]] = j;
        maxLen = MAX(maxLen , j - i + 1);
    }
    return maxLen;
}