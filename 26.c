#include <stdbool.h>

bool isPalindrome(int x) {
    // Special cases:
    // Negative numbers are not palindromes.
    // Numbers ending in 0 (except 0 itself) are not palindromes.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // Check equality for even or odd lengths
    return x == reversedHalf || x == reversedHalf / 10;
}
