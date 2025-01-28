class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        unordered_set<int> columns, diagonals, antiDiagonals;
        backtrack(n, 0, columns, diagonals, antiDiagonals, count);
        return count;
    }
    
    void backtrack(int n, int row, unordered_set<int>& columns, 
                   unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, 
                   int& count) {
        // Base case: if we've placed queens in all rows, increment the solution count
        if (row == n) {
            count++;
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            // Check if the column or diagonals are already occupied
            int diag = row - col;
            int antiDiag = row + col;
            if (columns.count(col) || diagonals.count(diag) || antiDiagonals.count(antiDiag)) {
                continue;  // Skip if the column or diagonal is attacked
            }
            
            // Place the queen at board[row][col]
            columns.insert(col);
            diagonals.insert(diag);
            antiDiagonals.insert(antiDiag);
            
            // Recurse to place the queen in the next row
            backtrack(n, row + 1, columns, diagonals, antiDiagonals, count);
            
            // Backtrack: remove the queen and try the next column
            columns.erase(col);
            diagonals.erase(diag);
            antiDiagonals.erase(antiDiag);
        }
    }
};
