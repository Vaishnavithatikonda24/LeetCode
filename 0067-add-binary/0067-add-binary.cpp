class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        string result = "";
        int carry = 0;
        
        // Traverse both strings from right to left
        while (i >= 0 || j >= 0 || carry) {
            // Add corresponding bits from a and b
            if (i >= 0) carry += a[i] - '0';  // Convert char to int
            if (j >= 0) carry += b[j] - '0';  // Convert char to int
            
            // Append current result bit (0 or 1)
            result = to_string(carry % 2) + result;
            
            // Update carry (either 0 or 1)
            carry /= 2;
            
            i--;
            j--;
        }
        
        return result;
    }
};
