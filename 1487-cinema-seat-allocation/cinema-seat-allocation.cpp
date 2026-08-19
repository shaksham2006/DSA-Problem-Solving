class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> reserved;
        for(auto seat:reservedSeats){
            reserved[seat[0]].push_back(seat[1]);
        }
        int ans=(n-reserved.size())*2;//since empty rows can hold 2 combination of seats
        for(auto row:reserved){
            vector<int> seats=row.second;
            bool flag=false;
            if(find(seats.begin(),seats.end(),2)==seats.end() &&
               find(seats.begin(),seats.end(),3)==seats.end() &&
               find(seats.begin(),seats.end(),4)==seats.end() &&
               find(seats.begin(),seats.end(),5)==seats.end()){
                ans++;
                flag=true;
            }
            if(find(seats.begin(),seats.end(),6)==seats.end() &&
               find(seats.begin(),seats.end(),7)==seats.end() &&
               find(seats.begin(),seats.end(),8)==seats.end() &&
               find(seats.begin(),seats.end(),9)==seats.end()){
                ans++;
                flag=true;
            }
            if(!flag){
                if(find(seats.begin(),seats.end(),4)==seats.end() &&
                   find(seats.begin(),seats.end(),5)==seats.end() &&
                   find(seats.begin(),seats.end(),6)==seats.end() &&
                   find(seats.begin(),seats.end(),7)==seats.end()){
                    ans++;
                }
            }
        }

        return ans;
    }
};