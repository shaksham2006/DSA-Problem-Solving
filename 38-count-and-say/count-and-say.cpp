class Solution {
public:
    string say(string s) {
        string ans = "";
        int i = 0;

        while (i < s.size()) {
            int cnt = 1;

            while (i + 1 < s.size() && s[i] == s[i + 1]) {
                cnt++;
                i++;
            }

            ans += to_string(cnt);
            ans += s[i];
            i++;
        }

        return ans;
    }

    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            ans = say(ans);
        }

        return ans;
    }
};