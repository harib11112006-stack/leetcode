#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Direct ASCII array lookup table initialized to -1
        std::vector<int> lastIndex(128, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If the character was seen before inside the current window,
            // jump the left boundary to the right of its last seen index
            if (lastIndex[currentChar] >= left) {
                left = lastIndex[currentChar] + 1;
            }
            
            // Update the character's last seen position
            lastIndex[currentChar] = right;
            
            // Calculate and track the maximum window size found
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
