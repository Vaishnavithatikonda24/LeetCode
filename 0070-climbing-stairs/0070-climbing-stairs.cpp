class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1; // If there's only 1 step, only one way to climb
        if (n == 2) return 2; // If there are 2 steps, two ways to climb

        int first = 1, second = 2;
        for (int i = 3; i <= n; i++) {
            int current = first + second;
            first = second;
            second = current;
        }
        return second; // The final result is in second
    }
};
