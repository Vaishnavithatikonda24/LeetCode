class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;  // Target found, return the index
            }
            else if (nums[mid] < target) {
                left = mid + 1;  // Target must be in the right half
            } else {
                right = mid - 1;  // Target must be in the left half
            }
        }
        
        return left;  // If target is not found, left is the insertion point
    }
};
