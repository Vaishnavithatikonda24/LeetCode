#include <sstream>
#include <vector>

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;
        
        // Split the path by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") continue;  // Ignore empty and current dir
            if (token == "..") {
                if (!stack.empty()) stack.pop_back();  // Move up a level
            } else {
                stack.push_back(token);  // Push valid directory
            }
        }
        
        // Reconstruct canonical path
        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            result += stack[i];
            if (i < stack.size() - 1) result += "/";
        }
        
        return result;
    }
};
