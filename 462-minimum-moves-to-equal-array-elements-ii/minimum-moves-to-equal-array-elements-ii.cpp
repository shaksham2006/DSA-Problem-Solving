class Solution {
public:
    int minMoves2(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1 ; i++){
            if(nums[i]!=nums[i+1]) break;
            if(i==nums.size()-2) return 0;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = n/2;
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans+=abs(nums[i]-nums[mid]);
        }
        return ans;
    }
};