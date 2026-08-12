class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        int wordLength = words[0].size();
        int numberOfWords = words.size();
        unordered_map<string, int> required;
        // Store how many times each word is required
        for (string word : words) {
            required[word]++;
        }
        // Try each possible starting position
        for (int start = 0; start < wordLength; start++) {
            int left = start;
            int numberOfWordsInWindow = 0;
            unordered_map<string, int> current;
            // Move right one complete word at a time
            for (int right = start;
                 right + wordLength <= s.size();
                 right += wordLength) {
                string word = s.substr(right, wordLength);
                // This word is not required
                if (required.find(word) == required.end()) {
                    current.clear();
                    numberOfWordsInWindow = 0;
                    left = right + wordLength;
                    continue;
                }
                // Add this word to current window
                current[word]++;
                numberOfWordsInWindow++;
                // Too many copies of this word
                while (current[word] > required[word]) {
                    string leftWord = s.substr(left, wordLength);
                    current[leftWord]--;
                    left += wordLength;
                    numberOfWordsInWindow--;
                }
                // We have exactly the required number of words
                if (numberOfWordsInWindow == numberOfWords) {
                    answer.push_back(left);
                    // Move left forward to search for another answer
                    string leftWord = s.substr(left, wordLength);
                    current[leftWord]--;
                    left += wordLength;
                    numberOfWordsInWindow--;
                }
            }
        }
        return answer;
    }
};