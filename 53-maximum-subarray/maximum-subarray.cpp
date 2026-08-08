class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;
        for(int val : nums){
            currentSum += val;
            maxSum = max(currentSum, maxSum);
            if(currentSum<0){
                currentSum=0;
            } else if(currentSum < val){
                currentSum = val;
            }
        }
        return maxSum;
    }


};