class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Traverse the array from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // No carry, just increment the digit
                return digits;
            }
            digits[i] = 0; // Set current digit to 0 and carry 1 to the next
        }
        
        // If we reached here, all digits were 9 and we need to add a leading 1
        digits.insert(digits.begin(), 1); // Insert 1 at the beginning
        return digits;
    }
};
