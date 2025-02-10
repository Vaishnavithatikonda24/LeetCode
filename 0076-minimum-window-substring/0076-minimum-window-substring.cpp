#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> targetFreq, windowFreq;
        for (char c : t) targetFreq[c]++;

        int left = 0, right = 0;
        int required = targetFreq.size();
        int formed = 0;
        int minLen = INT_MAX, minStart = 0;

        while (right < s.size()) {
            char c = s[right];
            windowFreq[c]++;
            if (targetFreq.find(c) != targetFreq.end() && windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            // Try to contract from the left
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // Remove leftmost character from the window
                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (targetFreq.find(leftChar) != targetFreq.end() && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;
                }
                left++; // Contract the window
            }

            right++; // Expand the window
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
