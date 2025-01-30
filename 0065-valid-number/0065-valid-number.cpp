#include <regex>
class Solution {
public:
    bool isNumber(string s) {
        // Regular expression to match a valid number
        regex pattern("^[+-]?(\\d+(\\.\\d*)?|\\.\\d+)([eE][+-]?\\d+)?$");
        
        // Check if the entire string matches the pattern
        return regex_match(s, pattern);
    }
};
