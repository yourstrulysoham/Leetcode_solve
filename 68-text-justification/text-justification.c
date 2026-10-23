/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** result = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    int current_length = 0;
    int start_index = 0;
    for (int i = 0; i < wordsSize; i++) {
        int word_length = strlen(words[i]);
        if (current_length + word_length + (i - start_index) > maxWidth) {
            int num_words = i - start_index;
            int num_spaces = maxWidth - current_length;
            result[*returnSize] = (char*)malloc((maxWidth + 1) * sizeof(char));
            int index = 0;
            if (num_words == 1) {
                strcpy(result[*returnSize], words[start_index]);
                for (int k = strlen(words[start_index]); k < maxWidth; k++) {
                    result[*returnSize][k] = ' ';
                }
                result[*returnSize][maxWidth] = '\0';
            } else {
                int spaces_between_words = num_spaces / (num_words - 1);
                int extra_spaces = num_spaces % (num_words - 1);
                for (int j = start_index; j < i - 1; j++) {
                    strcpy(&result[*returnSize][index], words[j]);
                    index += strlen(words[j]);
                    for (int k = 0; k < spaces_between_words; k++) {
                        result[*returnSize][index++] = ' ';
                    }
                    if (extra_spaces > 0) {
                        result[*returnSize][index++] = ' ';
                        extra_spaces--;
                    }
                }
                strcpy(&result[*returnSize][index], words[i - 1]);
            }
            (*returnSize)++;
            current_length = 0;
            start_index = i;
        }
        current_length += word_length;
    }
    result[*returnSize] = (char*)malloc((maxWidth + 1) * sizeof(char));
    int index = 0;
    for (int i = start_index; i < wordsSize - 1; i++) {
        strcpy(&result[*returnSize][index], words[i]);
        index += strlen(words[i]);
        result[*returnSize][index++] = ' ';
    }
    strcpy(&result[*returnSize][index], words[wordsSize - 1]);
    index += strlen(words[wordsSize - 1]);
    for (; index < maxWidth; index++) {
        result[*returnSize][index] = ' ';
    }
    result[*returnSize][maxWidth] = '\0';
    (*returnSize)++;
    return result;
}