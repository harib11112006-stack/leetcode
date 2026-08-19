#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // If count falls to 0, pick the current element as our new candidate
            if (count == 0) {
                candidate = num;
            }
            
            // Increment or decrement count based on candidate match status
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};
