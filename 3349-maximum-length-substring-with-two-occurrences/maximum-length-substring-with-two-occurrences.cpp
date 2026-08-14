class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxlen = INT_MIN;
        int freq[26] = {0};
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            freq[s[right]-'a']++;
            while(freq[s[right]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            maxlen = max(maxlen,right-left+1);
        }
        if (maxlen == INT_MIN){
            return 0;
        }
        return maxlen;

    }
};