class Solution {
public:
    string convert(string s,int numRows) {
        int n=s.size();
        if(numRows==1 || numRows>=n) return s;
        int col=n;
        vector<vector<char>>box(numRows,vector<char>(col,' '));
        int idx=0;
        for(int j=0;j<col;j++){
            for(int i=0;i<numRows;i++){
                if(idx!=n && j%(numRows-1)==0){
                    box[i][j]=s[idx];
                    idx++;
                }
                if(idx!=n && j%(numRows-1)!=0 &&
                   (i+j)%(numRows-1)==0){
                    box[i][j]=s[idx];
                    idx++;
                }
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<col;j++){
                if(box[i][j]==' ') continue;
                ans+=box[i][j];
            }
        }
        return ans;
    }
};