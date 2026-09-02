#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    
    // Allocate space for the prefix. Max length is bounded by the first string.
    int first_len = strlen(strs[0]);
    char* result = (char*)malloc((first_len + 1) * sizeof(char));
    
    for (int i = 0; i < first_len; i++) {
        char c = strs[0][i];
        
        for (int j = 1; j < strsSize; j++) {
            // Stop if string is too short or character mismatch occurs
            if (strs[j][i] == '\0' || strs[j][i] != c) {
                result[i] = '\0';
                return result;
            }
        }
        result[i] = c;
    }
    
    result[first_len] = '\0';
    return result;
}
