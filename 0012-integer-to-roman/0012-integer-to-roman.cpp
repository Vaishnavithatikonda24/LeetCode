class Solution {
public:
    string intToRoman(int num) {
        // Define the Roman numeral symbols and their corresponding values
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";

        // Loop through the Roman numeral mappings
        for (auto &[value, symbol] : roman) {
            // While the current value can fit into num
            while (num >= value) {
                result += symbol; // Append the symbol to the result
                num -= value;     // Subtract the value from num
            }
        }

        return result;
    }
};
