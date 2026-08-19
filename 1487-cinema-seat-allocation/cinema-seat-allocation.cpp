class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int,int> rows;

        for(auto seat:reservedSeats){
            if(seat[1]>=2 && seat[1]<=9)
                rows[seat[0]] |= 1<<(seat[1]-2);
        }

        int ans=(n-rows.size())*2;

        int left=15;
        int middle=60;
        int right=240;

        for(auto row:rows){

            int mask=row.second;
            bool l=(mask&left)==0;
            bool r=(mask&right)==0;

            if(l && r)
                ans+=2;
            else if(l || r)
                ans++;
            else if((mask&middle)==0)
                ans++;
        }

        return ans;
    }
};