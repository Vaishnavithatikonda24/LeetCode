class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Rearrange the numbers such that each number x is at index x-1.
        for (int i = 0; i < n; ++i) {
            // Only swap if nums[i] is in the range [1, n] and not already in the correct position.
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first index i such that nums[i] != i + 1
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all positions are correct, the smallest missing number is n + 1.
        return n + 1;
    }
};
