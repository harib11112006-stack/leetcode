#include <stdio.h>

int trap(int* height, int heightSize) {
    if (heightSize <= 2) return 0;
    
    int left = 0;
    int right = heightSize - 1;
    int left_max = 0;
    int right_max = 0;
    int total_water = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            // Process the left side because it's bounded by a larger right wall
            if (height[left] >= left_max) {
                left_max = height[left]; // Update maximum wall height on left
            } else {
                total_water += left_max - height[left]; // Accumulate trapped water
            }
            left++;
        } else {
            // Process the right side because it's bounded by a larger left wall
            if (height[right] >= right_max) {
                right_max = height[right]; // Update maximum wall height on right
            } else {
                total_water += right_max - height[right]; // Accumulate trapped water
            }
            right--;
        }
    }
    
    return total_water;
}
