class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long long exp = n;  // Use long long to avoid overflow
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= x;  // Multiply only if exponent is odd
            }
            x *= x;  // Square the base
            exp /= 2;  // Halve the exponent
        }
        return result;
    }
};
