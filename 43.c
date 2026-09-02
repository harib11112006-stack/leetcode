#include <stdbool.h>

// Helper function to calculate the next index in a circular array
int getNextIndex(int* nums, int numsSize, int i) {
    int next_idx = (i + nums[i]) % numsSize;
    if (next_idx < 0) {
        next_idx += numsSize;
    }
    return next_idx;
}

bool circularArrayLoop(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) continue;
        
        int slow = i;
        int fast = i;
        bool is_forward = nums[i] > 0;
        
        while (true) {
            if ((nums[slow] > 0) != is_forward || nums[slow] == 0) break;
            
            int fast_next1 = getNextIndex(nums, numsSize, fast);
            if ((nums[fast_next1] > 0) != is_forward || nums[fast_next1] == 0) break;
            
            fast = getNextIndex(nums, numsSize, fast_next1);
            if ((nums[fast] > 0) != is_forward || nums[fast] == 0) break;
            
            slow = getNextIndex(nums, numsSize, slow);
            
            if (slow == fast) {
                if (slow == getNextIndex(nums, numsSize, slow)) {
                    break;
                }
                return true;
            }
        }
        
        // Mark evaluated path components as 0 to avoid repeating work
        slow = i;
        while (nums[slow] != 0 && (nums[slow] > 0) == is_forward) {
            int next_slow = getNextIndex(nums, numsSize, slow);
            nums[slow] = 0;
            slow = next_slow;
        }
    }
    
    return false;
}
