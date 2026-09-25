class Solution {
public:
    vector<string> combine(vector<string> a, vector<string> b) {
        vector<string> result;
        for(string x : a) {
            for(string y : b) {
                result.push_back(x + y);
            }
        }
        return result;
    }
    // Handles concatenation
    vector<string> parseConcat(string &s, int &i) {
        vector<string> result = {""};
        while(i < s.size() && s[i] != '}' && s[i] != ',') {
            vector<string> current;
            if(s[i] == '{') {
                i++;  // skip {
                current = parseUnion(s, i);
                i++;  // skip }
            }
            else {
                current.push_back(string(1, s[i]));
                i++;
            }
            result = combine(result, current);
        }
        return result;
    }
    // Handles union
    vector<string> parseUnion(string &s, int &i) {
        vector<string> result;
        while(i < s.size() && s[i] != '}') {
            vector<string> current = parseConcat(s, i);
            result.insert(result.end(), current.begin(), current.end());
            if(i < s.size() && s[i] == ',') {
                i++;
            }
            else {
                break;
            }
        }
        return result;
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        vector<string> ans = parseUnion(expression, i);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};