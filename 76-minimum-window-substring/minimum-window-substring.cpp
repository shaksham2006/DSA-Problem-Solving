class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return {};
        }
        int freqt[256] = {0};
        int freqs[256] = {0};
        for (char ch : t) {
            freqt[ch]++;
        }
        int left = 0;
        int minLen = INT_MAX;
        int start = 0;
        for (int right = 0; right < s.size(); right++) {
            freqs[s[right]]++;
            bool window = true;
            for (int i = 0; i < 256; i++) {
                if (freqs[i] < freqt[i]) {
                    window = false;
                    break;
                }
            }
            while (window) {
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    start = left;
                }
                freqs[s[left]]--;
                left++;
                window = true;
                for (int i = 0; i < 256; i++) {
                    if (freqs[i] < freqt[i]) {
                        window = false;
                        break;
                    }
                }
            }
        }
        if (minLen == INT_MAX) {
            return {};
        }
        return s.substr(start, minLen);
    }
};