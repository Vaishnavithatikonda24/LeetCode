#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        
        // Helper function to expand around center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };
        
        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindrome (single character center)
            int len1 = expandAroundCenter(i, i);
            // Even-length palindrome (two character center)
            int len2 = expandAroundCenter(i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;  // Calculate the starting index of the palindrome
            }
        }
        
        return s.substr(start, maxLength);
    }
};
