#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_water = 0;
    
    while (left < right) {
        int width = right - left;
        int current_height = MIN(height[left], height[right]);
        
        int current_water = current_height * width;
        max_water = MAX(max_water, current_water);
        
        // Move the pointer that bottlenecks the container height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_water;
}
