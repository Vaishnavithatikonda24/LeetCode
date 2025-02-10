class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> rowFlags(m, false), colFlags(n, false);

        // Identify rows and columns that need to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowFlags[i] = true;
                    colFlags[j] = true;
                }
            }
        }

        // Zero out marked rows
        for (int i = 0; i < m; i++) {
            if (rowFlags[i]) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out marked columns
        for (int j = 0; j < n; j++) {
            if (colFlags[j]) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
