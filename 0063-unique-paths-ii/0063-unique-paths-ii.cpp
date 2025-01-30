class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Create a DP table with the same size as the obstacle grid
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the starting point
        if (obstacleGrid[0][0] == 0) {
            dp[0][0] = 1;  // There is one way to be at the starting point if no obstacle
        }
        
        // Fill the first column
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];  // Can only come from the top if no obstacle
            }
        }
        
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];  // Can only come from the left if no obstacle
            }
        }
        
        // Fill the rest of the grid
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];  // Sum of ways from top and left
                }
            }
        }
        
        // The bottom-right corner contains the answer
        return dp[m-1][n-1];
    }
};
