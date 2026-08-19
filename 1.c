#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Map to store value -> index mapping
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // Found the pair: return the complement index and current index
                return {numMap[complement], i};
            }
            
            // If not found, insert the current number and its index into the map
            numMap[nums[i]] = i;
        }
        
        // Return empty vector if no solution is found (guaranteed not to happen per constraints)
        return {};
    }
};
