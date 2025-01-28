class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> columns, diagonals, antiDiagonals;
        backtrack(n, 0, columns, diagonals, antiDiagonals, board, result);
        return result;
    }
    
    void backtrack(int n, int row, unordered_set<int>& columns, 
                   unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, 
                   vector<string>& board, vector<vector<string>>& result) {
        // Base case: if we've placed queens in all rows, add the current board to result
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            // Check if the column or diagonal is already occupied
            int diag = row - col;
            int antiDiag = row + col;
            if (columns.count(col) || diagonals.count(diag) || antiDiagonals.count(antiDiag)) {
                continue;  // Skip if the column or diagonal is attacked
            }
            
            // Place the queen at board[row][col]
            board[row][col] = 'Q';
            columns.insert(col);
            diagonals.insert(diag);
            antiDiagonals.insert(antiDiag);
            
            // Recurse to place the queen in the next row
            backtrack(n, row + 1, columns, diagonals, antiDiagonals, board, result);
            
            // Backtrack: remove the queen and try the next column
            board[row][col] = '.';
            columns.erase(col);
            diagonals.erase(diag);
            antiDiagonals.erase(antiDiag);
        }
    }
};
