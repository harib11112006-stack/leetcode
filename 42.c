int findDuplicate(int* nums, int numsSize) {
    // Phase 1: Find the intersection point of the tortoise and hare
    int slow = nums[0];
    int fast = nums[nums[0]];
    
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    
    // Phase 2: Find the entrance to the cycle (the duplicate number)
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}
