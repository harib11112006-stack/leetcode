int removeDuplicates(int* nums, int numsSize) {
    // If the array has 2 or fewer elements, no duplicates can violate the rule
    if (numsSize <= 2) {
        return numsSize;
    }
    
    // Start placing elements from index 2 onwards
    int insertIndex = 2;
    
    for (int i = 2; i < numsSize; i++) {
        // Compare current element with the element two positions behind the insertion point
        if (nums[i] != nums[insertIndex - 2]) {
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    
    return insertIndex;
}
