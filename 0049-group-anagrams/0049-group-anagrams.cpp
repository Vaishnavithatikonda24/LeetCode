class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        // Iterate through each string in the input
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());  // Sort the string
            
            // Use the sorted string as the key and add the original string to the group
            anagramGroups[sortedStr].push_back(str);
        }

        // Collect the result
        vector<vector<string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);  // Each value is a group of anagrams
        }

        return result;
    }
};
