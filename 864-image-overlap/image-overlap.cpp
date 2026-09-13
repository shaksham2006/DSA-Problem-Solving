class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        vector<pair<int,int>> ones;
        // Store positions of 1s in img1
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1)
                    ones.push_back({i,j});
            }
        }
        // Try every possible shift
        for(int dx=-(n-1);dx<n;dx++){
            for(int dy=-(n-1);dy<n;dy++){
                int count=0;
                // Check only positions where img1 has 1
                for(auto p:ones){
                    int x=p.first+dx;
                    int y=p.second+dy;
                    if(x>=0 && x<n && y>=0 && y<n &&
                       img2[x][y]==1){
                        count++;
                    }
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};