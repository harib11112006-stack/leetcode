#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    // Create an array to behave like a stack
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c; // Push operation
        } 
        else {
            if (top == -1) return false; // Stack empty, no open bracket to match
            
            char openBracket = stack[top];
            if ((c == ')' && openBracket == '(') || 
                (c == '}' && openBracket == '{') || 
                (c == ']' && openBracket == '[')) {
                top--; // Pop operation
            } else {
                return false; // Mismatched brackets
            }
        }
    }
    
    return top == -1; // True if stack is completely empty
}
                                      
