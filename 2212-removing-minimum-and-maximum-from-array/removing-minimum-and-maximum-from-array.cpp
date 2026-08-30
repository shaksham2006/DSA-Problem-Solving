class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0;
        int maxIdx = 0;
        int n = nums.size();
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]<nums[minIdx]){
                minIdx = i;

            }
            if(nums[i]>nums[maxIdx]){
                maxIdx = i;
            }
        }
        if(minIdx>maxIdx){
            swap(minIdx,maxIdx);
        }
        int left = maxIdx+1;
        int right = n - minIdx;
        int both = minIdx + 1 + n - maxIdx;
        return min({left,right,both});
    }
};