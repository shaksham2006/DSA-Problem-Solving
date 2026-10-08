class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        vector<string> subs;
        int start = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                count++;
            else
                count--;
            if(count == 0) {
                subs.push_back(s.substr(start, i - start + 1));
                start = i + 1;
            }
        }
        string ans = "";
        for(int i = 0; i < subs.size(); i++) {
            subs[i].erase(0, 1);
            subs[i].erase(subs[i].size() - 1, 1);
            ans += subs[i];
        }
        return ans;
    }
};