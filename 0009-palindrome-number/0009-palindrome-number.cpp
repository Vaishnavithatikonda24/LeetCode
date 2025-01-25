class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            // Extract the last digit and append it to reversedHalf
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // A number is a palindrome if:
        // - The first half of the number equals the reversed second half
        // - In the case of an odd number of digits, ignore the middle digit (reversedHalf / 10)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
