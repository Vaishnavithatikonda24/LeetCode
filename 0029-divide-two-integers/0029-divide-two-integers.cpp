#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        // Determine sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        
        // Convert to absolute values (use long to avoid overflow)
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        
        long long quotient = 0;
        
        // Perform division using bitwise shifts
        while (absDividend >= absDivisor) {
            long long temp = absDivisor, multiple = 1;
            
            // Find the largest multiple of divisor that fits in dividend
            while ((temp << 1) <= absDividend) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            // Subtract and add the multiple to the quotient
            absDividend -= temp;
            quotient += multiple;
        }
        
        // Apply the sign and return within 32-bit integer range
        return isNegative ? -quotient : quotient;
    }
};
