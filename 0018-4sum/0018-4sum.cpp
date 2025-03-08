#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        
        std::sort(nums.begin(), nums.end());  // Step 1: Sort the array
        
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate `i`
            
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicate `j`
                
                int left = j + 1, right = n - 1;
                long long newTarget = (long long)target - nums[i] - nums[j];

                while (left < right) {
                    int sum = nums[left] + nums[right];

                    if (sum == newTarget) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        
                        // Skip duplicate `left` values
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        // Skip duplicate `right` values
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    }
                    else if (sum < newTarget) {
                        ++left;  // Increase sum
                    }
                    else {
                        --right;  // Decrease sum
                    }
                }
            }
        }
        
        return result;
    }
};
