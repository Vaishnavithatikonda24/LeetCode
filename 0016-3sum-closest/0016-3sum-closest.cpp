#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closestSum = INT_MAX / 2; // Large initial value to avoid overflow
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                // If exact target is found, return immediately
                if (sum == target) return sum;
                
                // Update closest sum if needed
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                
                // Move pointers based on sum comparison
                if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return closestSum;
    }
};
