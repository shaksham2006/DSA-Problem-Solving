class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int freq[26] = {0};
        for (char ch : s1) {
            freq[ch - 'a']++;
        }
        int windowFreq[26] = {0};
        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            windowFreq[s2[right] - 'a']++;
            if (right - left + 1 > s1.size()) {
                windowFreq[s2[left] - 'a']--;
                left++;
            }
            if (right - left + 1 == s1.size()) {
                if (isFreqSame(freq, windowFreq))
                    return true;
            }
        }

        return false;
    }
};