class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, 0);

        for (int j = 0; j <= n; j++) dp[j] = j;

        for (int i = 1; i <= m; i++) {
            int prev_diag = dp[0]; // Store dp[i-1][j-1]
            dp[0] = i;  // Update first column for the current row
            
            for (int j = 1; j <= n; j++) {
                int temp = dp[j]; // Store current dp[j] before overwriting
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev_diag;
                } else {
                    dp[j] = 1 + min({dp[j], dp[j - 1], prev_diag});
                }
                prev_diag = temp; // Update prev_diag for next iteration
            }
        }
        return dp[n];
    }
};
