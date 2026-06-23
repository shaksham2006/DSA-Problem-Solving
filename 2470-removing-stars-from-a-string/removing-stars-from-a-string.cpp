class Solution {
public:
    string removeStars(string str) {
        stack<char> s;

        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '*') {
                if(!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(str[i]);
            }
        }

        string ans = "";

        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};