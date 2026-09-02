void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;          // Pointer to the end of valid elements in nums1
    int p2 = n - 1;          // Pointer to the end of nums2
    int p = m + n - 1;       // Pointer to the insertion index at the very back of nums1
    
    // Compare elements from the back and move the larger one to index p
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
    
    // If there are remaining elements in nums2, copy them over
    // If nums1 has remaining elements, they are already in their correct places
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}
