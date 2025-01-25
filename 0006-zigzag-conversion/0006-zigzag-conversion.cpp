#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // If there's only one row, return the string as it is
        if (numRows == 1) {
            return s;
        }

        // Initialize a vector of strings for the rows
        vector<string> rows(min(numRows, int(s.length())));  // There can't be more rows than characters
        
        int currentRow = 0;  // Start at the first row
        bool goingDown = false;  // Direction flag: down or up

        // Traverse the string and add characters to the rows
        for (char c : s) {
            rows[currentRow] += c;

            // If we're at the top or bottom row, change direction
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move up or down depending on the direction
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to form the result
        string result = "";
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};
