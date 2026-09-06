class Solution {
public:
    string convert(string s,int numRows) {
        int n=s.size();

        if(numRows==1 || numRows>=n) return s;

        vector<string>rows(numRows);

        int row=0;
        int direction=1;

        for(char c:s){
            rows[row]+=c;

            if(row==0)
                direction=1;

            if(row==numRows-1)
                direction=-1;

            row+=direction;
        }

        string ans="";

        for(string x:rows)
            ans+=x;

        return ans;
    }
};
// Don't store WHERE the character is in a matrix; just store WHICH ROW it belongs to.