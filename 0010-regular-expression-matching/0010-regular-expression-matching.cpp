class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        
        // DP table: dp[i][j] means whether s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches with empty pattern
        dp[0][0] = true;
        
        // Handle patterns with '*'
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    // Current characters match
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' can represent zero or more of the preceding character
                    dp[i][j] = dp[i][j - 2]; // Zero occurrence of the preceding character
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // One or more occurrences
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};
