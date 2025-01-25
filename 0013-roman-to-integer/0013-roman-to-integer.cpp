class Solution {
public:
    int romanToInt(string s) {
        // Map Roman symbols to their values
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0; // Result integer

        for (int i = 0; i < s.length(); ++i) {
            // If the current symbol is smaller than the next one, subtract its value
            if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                // Otherwise, add its value
                total += roman[s[i]];
            }
        }

        return total;
    }
};
