class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; // To store the elements in spiral order
        if (matrix.empty() || matrix[0].empty()) return result;

        int top = 0, bottom = matrix.size() - 1;    // Define top and bottom bounds
        int left = 0, right = matrix[0].size() - 1; // Define left and right bounds

        while (top <= bottom && left <= right) {
            // Traverse from left to right along the top row
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++; // Move the top boundary down

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left

            // Traverse from right to left along the bottom row, if within bounds
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left column, if within bounds
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }

        return result;
    }
};
