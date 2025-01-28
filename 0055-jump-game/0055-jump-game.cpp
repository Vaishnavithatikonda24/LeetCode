class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0; // Tracks the farthest position reachable
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                // If the current index is beyond the farthest reachable index, return false
                return false;
            }
            maxReach = max(maxReach, i + nums[i]); // Update the farthest reachable index
            if (maxReach >= n - 1) {
                // If we can reach or exceed the last index, return true
                return true;
            }
        }

        return false;
    }
};
