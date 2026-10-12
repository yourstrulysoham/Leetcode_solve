


#pragma GCC push_options
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("arch=x86-64-v3")

static int cmp(const void *s1, const void *s2) {
    return strlen(*(const char **)s1) - strlen(*(const char **)s2);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    qsort(strs, strsSize, sizeof(strs[0]), cmp);
    int m[10 * 1024][26] = { 0 };
    size_t sl[strsSize];
    for (int i = 0 ; i < strsSize ; i++) {
        sl[i] = strlen(strs[i]);
        for (char *s = strs[i] ; *s ; s++)
            m[i][*s - 'a']++;
    }
    char ***s = malloc(sizeof(char **[strsSize]));
    *returnColumnSizes = malloc(sizeof(int [10 * 1024]));
    int k = 0;
    for (int i = 0 ; i < strsSize ; i++) {
        int z = 0, l = strs[i] ? sl[i] : 0;
        s[k] = NULL;
        for (int j = i + 1 ; strs[i] && j < strsSize ; j++) {
            if (strs[j] && l < sl[j])
                break;
            if (strs[j] && !memcmp(&m[i], &m[j], sizeof m[i])) {
                if (!s[k])
                    s[k] = malloc(sizeof(char *[100]));
                if (z == 0)
                    s[k][z++] = strs[i];
                s[k][z++] = strs[j];
                strs[j] = NULL;
            }
        }
        if (s[k]) {
            (*returnColumnSizes)[k] = z;
            k++;
        } else if (strs[i]) {
            s[k] = malloc(sizeof(char *[100]));        
            s[k][z++] = strs[i];
            (*returnColumnSizes)[k] = z;            
            k++;
        }
    }
    *returnSize = k;
    return s;
}

