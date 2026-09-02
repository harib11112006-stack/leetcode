#include <stdbool.h>

// Helper function to calculate the sum of the squares of digits
int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
        int d = n % 10;
        totalSum += d * d;
        n /= 10;
    }
    return totalSum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    
    // Move slow pointer by 1 step and fast pointer by 2 steps
    while (fast != 1 && slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    
    // If the fast pointer reached 1, it is a happy number
    return fast == 1;
}

