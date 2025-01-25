class Solution {
public:
    bool isValid(string s) {
        // Create a stack to store open brackets
        stack<char> st;
        
        // Iterate over each character in the string
        for (char c : s) {
            // If the character is an open bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // If it's a closing bracket, check if it matches the top of the stack
            else {
                if (st.empty()) {
                    return false;  // No open bracket to match with
                }
                
                // Check the top of the stack for the matching opening bracket
                char top = st.top();
                if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                    st.pop();  // Match found, pop the top element
                } else {
                    return false;  // Mismatch found
                }
            }
        }
        
        // If the stack is empty, all brackets are matched
        return st.empty();
    }
};
