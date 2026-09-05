class Solution {
public:
    bool ValidityCheck(vector<vector<char>>& board,int row,int column){
        for(int i=0;i<row;i++){
            unordered_map<char,int>freq;
            for(int j=0;j<column;j++){
                if(board[i][j]=='.') continue;
                freq[board[i][j]]++;
                if(freq[board[i][j]]>1) return false;
            }
        }
        for(int j=0;j<column;j++){
            unordered_map<char,int>freq;
            for(int i=0;i<row;i++){
                if(board[i][j]=='.') continue;
                freq[board[i][j]]++;
                if(freq[board[i][j]]>1) return false;
            }
        }
        for(int a=0;a<9;a+=3){
            for(int b=0;b<9;b+=3){
                unordered_map<char,int>freq;
                for(int i=a;i<a+3;i++){
                    for(int j=b;j<b+3;j++){
                        if(board[i][j]=='.') continue;
                        freq[board[i][j]]++;
                        if(freq[board[i][j]]>1) return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        return ValidityCheck(board,n,m);
    }
};