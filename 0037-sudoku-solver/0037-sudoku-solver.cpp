#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    // Backtracking function to solve the Sudoku puzzle
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {  // If the cell is empty
                    for (char num = '1'; num <= '9'; num++) {  // Try each digit from '1' to '9'
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;  // Place the number in the cell
                            if (solve(board)) {
                                return true;  // If placing the number leads to a solution, return true
                            }
                            board[i][j] = '.';  // Backtrack if no solution found
                        }
                    }
                    return false;  // If no number is valid, return false
                }
            }
        }
        return true;  // If all cells are filled, the board is solved
    }
    
    // Check if placing 'num' in board[i][j] is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Check if 'num' is in the current row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) {
                return false;
            }
        }
        
        // Check if 'num' is in the current column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }
        
        // Check if 'num' is in the 3x3 sub-box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        
        return true;  // 'num' is valid in this cell
    }
};
