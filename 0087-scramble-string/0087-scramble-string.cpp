#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        string key = s1 + "#" + s2;  // Unique key for memoization
        if (memo.find(key) != memo.end()) return memo[key];

        int n = s1.length();
        string sorted1 = s1, sorted2 = s2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());

        if (sorted1 != sorted2) return memo[key] = false; // Pruning step

        for (int i = 1; i < n; i++) {
            // Check without swap
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            // Check with swap
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }
};
