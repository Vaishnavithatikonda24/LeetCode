class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        
        // If either number is zero, the result is zero
        if (num1 == "0" || num2 == "0") return "0";
        
        // Initialize a result vector to hold the multiplication results
        vector<int> result(m + n, 0);
        
        // Multiply each digit of num1 with each digit of num2
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + result[i + j + 1]; // Add previous value at this position
                result[i + j + 1] = sum % 10; // Store the digit at the current place
                result[i + j] += sum / 10;   // Add the carry to the next place
            }
        }
        
        // Convert the result to a string
        string res = "";
        for (int i = 0; i < result.size(); ++i) {
            // Skip leading zeros
            if (!(res.empty() && result[i] == 0)) {
                res += to_string(result[i]);
            }
        }
        
        return res;
    }
};
