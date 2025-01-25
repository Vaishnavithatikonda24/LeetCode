class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  // Special case for 0 and 1
        
        int low = 0, high = x;
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long square = (long long)mid * mid;  // Avoid overflow
            
            if (square == x) {
                return mid;  // Exact match
            }
            else if (square < x) {
                low = mid + 1;  // Search in the higher half
                result = mid;   // Save the largest mid where mid^2 <= x
            }
            else {
                high = mid - 1;  // Search in the lower half
            }
        }
        
        return result;  // Return the floor value of the square root
    }
};
