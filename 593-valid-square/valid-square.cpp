class Solution {
public:
    bool validSquare(vector<int>& p1,vector<int>& p2,vector<int>& p3,vector<int>& p4) {
        vector<vector<int>>p={p1,p2,p3,p4};
        vector<int>sides;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                int side=(p[i][0]-p[j][0])*(p[i][0]-p[j][0])+
                         (p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
                sides.push_back(side);
            }
        }
        sort(sides.begin(),sides.end());
        if(sides[0]==0) return false;
        return sides[0]==sides[1] &&
               sides[0]==sides[2] &&
               sides[0]==sides[3] &&
               sides[4]==sides[5] &&
               sides[4]==2*sides[0];
    }
};

// sides4 and side5 are diagonals and without sqrt they are twice the sides of square