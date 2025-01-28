#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);  // Initialize with -1 to handle the base case
        int maxLength = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);  // Push the index of '(' onto the stack
            } else {
                stk.pop();  // Pop the last index (which is '(')
                
                if (stk.empty()) {
                    stk.push(i);  // If the stack is empty, push the current index as base
                } else {
                    // Calculate the valid length of the current substring
                    maxLength = max(maxLength, i - stk.top());
                }
            }
        }
        
        return maxLength;
    }
};
