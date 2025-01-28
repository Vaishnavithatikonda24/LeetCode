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
            // If the number is greater than the target, skip it
            if (candidates[i] > target) continue;

            // Include the candidate number in the current combination
            current.push_back(candidates[i]);

            // Recur with the reduced target and the same start index (allow repetition)
            backtrack(candidates, target - candidates[i], i, current, result);

            // Backtrack: remove the last added number to try the next one
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};
