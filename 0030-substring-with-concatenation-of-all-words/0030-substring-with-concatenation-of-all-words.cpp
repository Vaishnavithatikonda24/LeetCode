#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int substringLength = wordLength * wordCount;

        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        for (int i = 0; i < wordLength; i++) {
            int left = i, count = 0;
            unordered_map<string, int> windowMap;

            for (int right = i; right + wordLength <= s.size(); right += wordLength) {
                string word = s.substr(right, wordLength);
                if (wordMap.find(word) != wordMap.end()) {
                    windowMap[word]++;
                    count++;

                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLength);
                        windowMap[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    windowMap.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }

        return result;
    }
};
