class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, current_end = 0, farthest = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest we can reach from the current position
            farthest = max(farthest, i + nums[i]);
            
            // If we have reached the end of the current jump
            if (i == current_end) {
                // Make another jump
                jumps++;
                current_end = farthest;
            }
        }
        
        return jumps;
    }
};
