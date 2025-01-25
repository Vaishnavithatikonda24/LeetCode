class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;                  // Pointer to the left side
        int right = height.size() - 1; // Pointer to the right side
        int maxArea = 0;               // Maximum water area

        while (left < right) {
            // Calculate the current area
            int currentArea = min(height[left], height[right]) * (right - left);
            // Update the maximum area if current area is larger
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
