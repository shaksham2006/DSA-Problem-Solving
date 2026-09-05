class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int Max = INT_MIN;
        vector<int>minVal;
        int Min= INT_MAX;
        for(int i = n-1; i >= 0; i--){
            Min = min(Min,nums[i]);
            minVal.push_back(Min);
        }
        for(int i = 0; i < n; i++){
            Max = max(Max,nums[i]);
            if((Max-minVal[n-1-i])<=k) return i;
        }
        return -1;
    }
};