int removeElement(int* nums, int numsSize, int val) {
    int insertIndex = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // If the current element is not the value we want to remove
        if (nums[i] != val) {
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    
    // insertIndex now represents the count of elements not equal to val
    return insertIndex;
}
