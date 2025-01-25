class Solution {
public:
    int strStr(string haystack, string needle) {
        // Use the find() function to find the first occurrence of needle in haystack
        int index = haystack.find(needle);
        
        // If needle is found, return the index, otherwise return -1
        return (index != string::npos) ? index : -1;
    }
};
