class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;  // Using long long to handle overflow during calculation

        while (x != 0) {
            int digit = x % 10;  // Get the last digit
            reversed = reversed * 10 + digit;  // Shift and add the digit

            // Check for overflow: 32-bit signed integer range is [-2^31, 2^31 - 1]
            if (reversed > INT_MAX || reversed < INT_MIN) {
                return 0;  // Return 0 if the reversed value exceeds 32-bit range
            }

            x /= 10;  // Remove the last digit
        }

        return (int)reversed;  // Return the reversed integer
    }
};
