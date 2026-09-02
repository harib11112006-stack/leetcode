#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum((unsigned char)s[left])) {
            left++;
        }
        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum((unsigned char)s[right])) {
            right--;
        }
        
        // Compare lowercase versions of the characters
        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}
