class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> currentLine;
        int currentLength = 0;
        
        for (const string& word : words) {
            // If adding the current word would exceed maxWidth
            if (currentLength + word.length() + currentLine.size() > maxWidth) {
                // Justify the current line
                result.push_back(justifyLine(currentLine, maxWidth, false));
                // Start a new line with the current word
                currentLine = {word};
                currentLength = word.length();
            } else {
                // Add the word to the current line
                currentLine.push_back(word);
                currentLength += word.length();
            }
        }
        
        // Handle the last line (left-justified)
        result.push_back(justifyLine(currentLine, maxWidth, true));
        
        return result;
    }
    
    string justifyLine(vector<string>& words, int maxWidth, bool isLastLine) {
        int numWords = words.size();
        
        // If this is the last line, it should be left-justified
        if (isLastLine) {
            string line = "";
            for (int i = 0; i < numWords; ++i) {
                line += words[i];
                if (i != numWords - 1) {
                    line += " ";
                }
            }
            // Add spaces at the end of the last line
            int remainingSpaces = maxWidth - line.length();
            line += string(remainingSpaces, ' ');
            return line;
        }
        
        // If not the last line, justify the words
        int totalChars = 0;
        for (const string& word : words) {
            totalChars += word.length();
        }
        
        int totalSpaces = maxWidth - totalChars;
        if (numWords == 1) {
            // Special case for a line with only one word: just add spaces to the right
            return words[0] + string(totalSpaces, ' ');
        }
        
        int spacesBetweenWords = totalSpaces / (numWords - 1); // even spaces between words
        int extraSpaces = totalSpaces % (numWords - 1); // remaining spaces
        
        string line = words[0];
        for (int i = 1; i < numWords; ++i) {
            int spacesToInsert = spacesBetweenWords + (i <= extraSpaces ? 1 : 0); // Distribute extra spaces
            line += string(spacesToInsert, ' ') + words[i];
        }
        
        return line;
    }
};
