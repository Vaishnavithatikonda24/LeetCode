class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // Handle empty array case
        
        string prefix = strs[0];  // Start with the first string as the prefix
        
        for (int i = 1; i < strs.size(); ++i) {
            // Compare prefix with the current string and update prefix
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }
            prefix = prefix.substr(0, j);  // Update the prefix to the common part
            
            if (prefix.empty()) return "";  // If no common prefix, return empty string
        }
        
        return prefix;  // Return the longest common prefix
    }
};
