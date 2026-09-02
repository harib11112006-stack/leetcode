int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    // Pointer indicating the index to place the next unique element
    int insertIndex = 1;
    
    for (int i = 1; i < numsSize; i++) {
        // If current element is different from the previous one, it's unique
        if (nums[i] != nums[i - 1]) {
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }
    
    return insertIndex;
}
