#include <string.h>

int strStr(char* haystack, char* needle) {
    // strstr finds the first occurrence of needle in haystack
    char* ptr = strstr(haystack, needle);
    
    // If ptr is NULL, the needle was not found
    if (ptr == NULL) {
        return -1;
    }
    
    // Pointer subtraction gives the index of the occurrence
    return ptr - haystack;
}
