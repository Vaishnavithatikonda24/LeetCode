class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; // Return an empty vector if input is empty
        
        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged; // To store merged intervals
        
        for (const auto& interval : intervals) {
            // If merged is empty or the current interval does not overlap with the last interval in merged
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval); // Add the interval to merged
            } else {
                // Overlapping intervals, merge them
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};
