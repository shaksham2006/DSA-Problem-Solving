class Solution {
public:
    int minMoves(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1 ; i++){
            if(nums[i]!=nums[i+1]) break;
            if(i==nums.size()-2) return 0;
        }
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += maxi - nums[i];
        }
        return ans;
    }
};