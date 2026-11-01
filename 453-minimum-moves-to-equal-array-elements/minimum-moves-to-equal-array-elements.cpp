class Solution {
public:
    int minMoves(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1 ; i++){
            if(nums[i]!=nums[i+1]) break;
            if(i==nums.size()-2) return 0;
        }
        int mini = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ans += nums[i] - mini;
        }
        return ans;
    }
};

//since incrementing n-1 elements by one is equivalent to decrementing every element by one at a time till all are same and for being same each should be the min there for nums[i]- mini