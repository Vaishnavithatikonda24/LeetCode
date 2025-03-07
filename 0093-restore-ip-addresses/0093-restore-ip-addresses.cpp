class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> current;
        
        backtrack(s, 0, current, result);
        return result;
    }
    
private:
    void backtrack(const string& s, int start, vector<string>& current, vector<string>& result) {
        if (current.size() == 4) {
            if (start == s.length()) {
                result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            }
            return;
        }
        
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.length()) break;
            string part = s.substr(start, len);
            
            if (isValid(part)) {
                current.push_back(part);
                backtrack(s, start + len, current, result);
                current.pop_back();
            }
        }
    }
    
    bool isValid(const string& part) {
        if (part.length() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }
};