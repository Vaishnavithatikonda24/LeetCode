class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Mapping of digits to letters
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        // If the input string is empty, return an empty vector
        if (digits.empty()) {
            return {};
        }
        
        vector<string> result;
        string currentCombination;
        backtrack(digits, 0, currentCombination, result, mapping);
        return result;
    }
    
    // Backtracking function to generate combinations
    void backtrack(const string& digits, int index, string& currentCombination, 
                   vector<string>& result, const vector<string>& mapping) {
        // Base case: if we have processed all digits, add the current combination to the result
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }
        
        // Get the current digit and the corresponding letters
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        
        // Try all possible letters for the current digit
        for (char letter : letters) {
            currentCombination.push_back(letter); // Add the letter to the current combination
            backtrack(digits, index + 1, currentCombination, result, mapping); // Recurse to the next digit
            currentCombination.pop_back(); // Backtrack, remove the last letter
        }
    }
};
