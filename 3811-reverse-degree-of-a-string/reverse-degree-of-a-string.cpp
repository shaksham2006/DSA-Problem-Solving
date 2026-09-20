class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int>m;
        int a = 26;
        for(char i = 'a'; i <= 'z';i++){
            m[i]=a;
            a--;
        }
        int ans = 0;
        for(int i = 1; i <= s.size(); i++){
            ans += i*m[s[i-1]];
        }
        return ans;
    }
};