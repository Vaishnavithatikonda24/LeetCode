class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // Pointer to track where to place the non-val elements
        
        // Iterate through the array with pointer `j`
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) { // If the element is not equal to `val`
                nums[i] = nums[j]; // Place it at the current valid position
                i++; // Move the pointer `i` to the next position
            }
        }
        
        // `i` will represent the number of elements not equal to `val`
        return i;
    }
};
