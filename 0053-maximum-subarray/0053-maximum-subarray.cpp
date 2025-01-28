class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0]; // Initialize max sum as the first element
        int currentSum = nums[0]; // Initialize current sum as the first element

        // Traverse the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // Update the current sum to include the current element
            // or start a new subarray at the current element
            currentSum = max(nums[i], currentSum + nums[i]);

            // Update the maximum sum if current sum is larger
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
