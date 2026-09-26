class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(int i = 0; i < knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        vector<pair<int,string>> keys;
        int i = 0;
        while(i < s.size()){
            if(s[i] == '('){
                int idx = i;
                string key = "";
                i++;
                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }
                keys.push_back({idx, key});
            }
            i++;
        }
        // Replace from right to left
        for(int i = keys.size() - 1; i >= 0; i--){
            int idx = keys[i].first;
            string key = keys[i].second;
            string value = "?";
            if(mp.count(key)){
                value = mp[key];
            }
            s.replace(idx, key.size() + 2, value);
        }
        return s;
    }
};