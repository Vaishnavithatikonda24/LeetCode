class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, vector<bool>& used) {
        // If the current permutation is complete (i.e., temp size == nums size), add it to result
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip if the number is already used or if it's a duplicate and hasn't been used in the previous iteration
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }
            
            // Mark this element as used and include it in the current permutation
            used[i] = true;
            temp.push_back(nums[i]);
            
            // Recurse to build the next element of the permutation
            backtrack(nums, result, temp, used);
            
            // Backtrack: Unmark this element as used and remove it from the current permutation
            used[i] = false;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        
        // Sort the input array to handle duplicates
        sort(nums.begin(), nums.end());
        
        backtrack(nums, result, temp, used);
        return result;
    }
};
