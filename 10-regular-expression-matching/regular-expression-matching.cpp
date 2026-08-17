class Solution {
public:
    bool solve(string& s,string& p,int i,int j){
        if(j==p.size()){
            return i==s.size();
        }
        bool match=i<s.size() && (s[i]==p[j] || p[j]=='.');
        if(j+1<p.size() && p[j+1]=='*'){
            if(solve(s,p,i,j+2))
                return true;
            if(match && solve(s,p,i+1,j))
                return true;
            return false;
        }
        if(match)
            return solve(s,p,i+1,j+1);
        return false;
    }

    bool isMatch(string s,string p){
        return solve(s,p,0,0);
    }
};