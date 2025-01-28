class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n)); // Create an n x n matrix
        int top = 0, bottom = n - 1;                  // Define top and bottom bounds
        int left = 0, right = n - 1;                  // Define left and right bounds
        int num = 1;                                  // Start filling from 1
        
        while (top <= bottom && left <= right) {
            // Fill the top row from left to right
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++; // Move the top boundary down

            // Fill the right column from top to bottom
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--; // Move the right boundary left

            // Fill the bottom row from right to left, if within bounds
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    matrix[bottom][i] = num++;
                }
                bottom--; // Move the bottom boundary up
            }

            // Fill the left column from bottom to top, if within bounds
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    matrix[i][left] = num++;
                }
                left++; // Move the left boundary right
            }
        }

        return matrix;
    }
};
