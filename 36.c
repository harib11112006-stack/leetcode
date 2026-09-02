#include <stdlib.h>
#include <string.h>

void backtrack(char** result, int* returnSize, char* current, int index, int open, int close, int n) {
    // Base Case: Valid combination completed
    if (index == n * 2) {
        current[index] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    // Rule 1: Add opening parenthesis
    if (open < n) {
        current[index] = '(';
        backtrack(result, returnSize, current, index + 1, open + 1, close, n);
    }

    // Rule 2: Add closing parenthesis
    if (close < open) {
        current[index] = ')';
        backtrack(result, returnSize, current, index + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    // Catalan Number formula predicts a max of 1430 unique configurations for n = 8
    int capacity = 1500; 
    char** result = (char**)malloc(capacity * sizeof(char*));
    *returnSize = 0;

    // Workspace string array to build current combinations sequentially
    char* current = (char*)malloc((n * 2 + 1) * sizeof(char));

    backtrack(result, returnSize, current, 0, 0, 0, n);

    free(current);
    return result;
}
