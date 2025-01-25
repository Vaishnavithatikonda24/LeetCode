#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;  // map to store the number and its index
        vector<int> result;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                // If found, return the pair of indices
                result.push_back(num_map[complement]);
                result.push_back(i);
                return result;
            }
            
            // If not found, store the current number and its index
            num_map[nums[i]] = i;
        }
        
        return result;  // This line is technically unnecessary since we are promised a solution
    }
};
