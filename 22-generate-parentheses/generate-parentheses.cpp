class Solution {
public:
    void generate(vector<string>& ans,string& str,int n,int open,int close){
        if(str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            generate(ans,str,n,open+1,close);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            generate(ans,str,n,open,close+1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        string str;
        generate(ans,str,n,0,0);
        return ans;
    }
};