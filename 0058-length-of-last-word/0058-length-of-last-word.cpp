class Solution {
public:
    int lengthOfLastWord(string s) {
        // Step 1: Trim the trailing spaces
        int n = s.length();
        int i = n - 1;
        
        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Step 2: Count the length of the last word
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};
