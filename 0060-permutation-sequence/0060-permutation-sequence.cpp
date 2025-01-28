class Solution {
public:
    string getPermutation(int n, int k) {
        // Step 1: Create a list of numbers from 1 to n
        vector<int> numbers;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }
        
        // Step 2: Calculate factorials for numbers up to n
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        
        // Step 3: Convert k to zero-based index
        k -= 1;
        
        // Step 4: Generate the k-th permutation
        string result = "";
        for (int i = n; i > 0; --i) {
            int idx = k / factorial[i - 1]; // Determine the index in the current set
            result += to_string(numbers[idx]); // Add the number at the index to the result
            numbers.erase(numbers.begin() + idx); // Remove the used number
            k %= factorial[i - 1]; // Update k for the next position
        }
        
        return result;
    }
};
