class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        // If the target is 0, we've found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Try every candidate starting from index 'start'
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates: If this is the same as the previous number, skip it
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // If the current number exceeds the target, stop further exploration
            if (candidates[i] > target) continue;

            // Include the current number in the combination
            current.push_back(candidates[i]);

            // Recur with the reduced target and the next number
            backtrack(candidates, target - candidates[i], i + 1, current, result);

            // Backtrack: remove the last added number to try the next one
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
