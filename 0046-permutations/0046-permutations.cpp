class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // If we have reached the end of the array, store the current permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        // Iterate over the elements starting from the 'start' index
        for (int i = start; i < nums.size(); i++) {
            // Swap the current index with the loop index
            swap(nums[start], nums[i]);
            
            // Recursively generate permutations for the next index
            backtrack(nums, start + 1, result);
            
            // Backtrack by swapping back the elements
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};
