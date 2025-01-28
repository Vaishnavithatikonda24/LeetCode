class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;  // Edge case: no heights, no water to trap
        
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water_trapped = 0;
        
        while (left <= right) {
            if (height[left] <= height[right]) {
                // Process the left pointer
                if (height[left] >= left_max) {
                    left_max = height[left];  // Update the left_max
                } else {
                    water_trapped += left_max - height[left];  // Calculate water trapped
                }
                left++;
            } else {
                // Process the right pointer
                if (height[right] >= right_max) {
                    right_max = height[right];  // Update the right_max
                } else {
                    water_trapped += right_max - height[right];  // Calculate water trapped
                }
                right--;
            }
        }
        
        return water_trapped;
    }
};
