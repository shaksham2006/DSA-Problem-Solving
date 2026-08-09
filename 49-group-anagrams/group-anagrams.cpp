class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        int n = strs.size();

        vector<bool> used(n, false);

        for(int i = 0; i < n; i++) {

            if(used[i])
                continue;

            vector<string> ans;

            int freq1[26] = {0};

            for(char c : strs[i]) {
                freq1[c - 'a']++;
            }

            ans.push_back(strs[i]);
            used[i] = true;

            for(int j = i + 1; j < n; j++) {

                if(used[j])
                    continue;

                int freq2[26] = {0};

                for(char c : strs[j]) {
                    freq2[c - 'a']++;
                }

                bool same = true;

                for(int k = 0; k < 26; k++) {
                    if(freq1[k] != freq2[k]) {
                        same = false;
                        break;
                    }
                }

                if(same) {
                    ans.push_back(strs[j]);
                    used[j] = true;
                }
            }

            answer.push_back(ans);
        }

        return answer;
    }
};