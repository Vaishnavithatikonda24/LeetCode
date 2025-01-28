class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap; // Map to store the last index of characters
        int maxLength = 0; // To track the maximum length of substring
        int start = 0; // Start of the current window

        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            // If the character is already in the map and within the current window
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1; // Move the start of the window
            }
            charIndexMap[currentChar] = end; // Update the last index of the character
            maxLength = max(maxLength, end - start + 1); // Calculate the max length
        }

        return maxLength;
    }
};
