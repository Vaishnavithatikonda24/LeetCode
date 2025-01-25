class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;  // Edge case: empty array
        
        int i = 1;  // Start from the second element (index 1)
        
        for (int j = 1; j < nums.size(); j++) {
            // If current element is different from the last unique element
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];  // Place it at the next available position
                i++;  // Increment the index for the next unique element
            }
        }
        
        return i;  // Return the count of unique elements
    }
};
