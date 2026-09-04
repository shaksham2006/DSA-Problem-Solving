class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int Max = INT_MIN;
        for(int i = 0; i < n; i++){
            int Min= INT_MAX;
            Max = max(Max,nums[i]);
            for(int j = i; j < n; j++){
                Min = min(Min,nums[j]);
            }
            if((Max-Min)<=k) return i;
        }
        return -1;
    }
};