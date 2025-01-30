class Solution {
public:
    int uniquePaths(int m, int n) {
        long long result = 1;
        for (int i = 1; i < m; ++i) {
            result = result * (n + i - 1) / i;
        }
        return (int) result;
    }
};
