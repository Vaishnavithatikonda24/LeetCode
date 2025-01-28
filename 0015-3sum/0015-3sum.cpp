class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements to avoid repeated triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;

            // Use two-pointer technique to find the two other elements
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return result;
    }
};
