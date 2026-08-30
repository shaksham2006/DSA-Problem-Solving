class Solution {
public:
    void Combinations(vector<string>& ans,string& digits,int idx,string& str,unordered_map<char,string>& dailpad){
        if(idx==digits.size()){
            ans.push_back(str);
            return;
        }
        string letters=dailpad[digits[idx]];
        for(char ch:letters){
            str.push_back(ch);
            Combinations(ans,digits,idx+1,str,dailpad);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits){
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        unordered_map<char,string> dailpad;
        dailpad['2']="abc";
        dailpad['3']="def";
        dailpad['4']="ghi";
        dailpad['5']="jkl";
        dailpad['6']="mno";
        dailpad['7']="pqrs";
        dailpad['8']="tuv";
        dailpad['9']="wxyz";
        string str;
        Combinations(ans,digits,0,str,dailpad);
        return ans;
    }
};