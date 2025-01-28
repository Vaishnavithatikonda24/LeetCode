class Solution {
public:
    string countAndSay(int n) {
        // Start with the base case for n = 1
        string result = "1";
        
        // Generate countAndSay(n) for n > 1
        for (int i = 2; i <= n; ++i) {
            string temp = "";
            int count = 1;
            
            // Traverse the current result string
            for (int j = 1; j < result.length(); ++j) {
                // If current digit is the same as the previous one, increase the count
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    // If different, append the count and the character to the temp string
                    temp += to_string(count) + result[j - 1];
                    count = 1;  // Reset count for the new character
                }
            }
            // Append the last group of characters to temp
            temp += to_string(count) + result[result.length() - 1];
            result = temp;  // Set result to the newly formed string
        }
        
        return result;
    }
};
