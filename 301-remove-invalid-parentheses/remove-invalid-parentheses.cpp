class Solution {
public:
    unordered_set<string> ans;
    void solve(string &s, int index, int left, int right, int balance, string &current) {
        if(s.size() - index < left + right)
            return;
        if(index == s.size()) {
            if(left == 0 && right == 0 && balance == 0)
                ans.insert(current);
            return;
        }
        if(s[index] == '(') {
            if(left > 0)
                solve(s, index + 1, left - 1, right, balance, current);
            current.push_back('(');
            solve(s, index + 1, left, right, balance + 1, current);
            current.pop_back();
        }
        else if(s[index] == ')') {
            if(right > 0)
                solve(s, index + 1, left, right - 1, balance, current);
            if(balance > 0) {
                current.push_back(')');
                solve(s, index + 1, left, right, balance - 1, current);
                current.pop_back();
            }
        }
        else {
            current.push_back(s[index]);
            solve(s, index + 1, left, right, balance, current);
            current.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(char c : s) {
            if(c == '(') {
                left++;
            }
            else if(c == ')') {
                if(left > 0)
                    left--;
                else
                    right++;
            }
        }
        string current = "";
        solve(s, 0, left, right, 0, current);
        return vector<string>(ans.begin(), ans.end());
    }
};