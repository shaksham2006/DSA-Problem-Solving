class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = INT_MAX;

        unordered_map<int, int> rightSum;

        int sum = 0;

        // Store sum of elements removed from right
        for(int right = n - 1; right >= 0; right--){
            sum += nums[right];
            rightSum[sum] = n - right;
        }

        sum = 0;

        // Try removing different numbers from left
        for(int left = 0; left <= n; left++){

            if(left > 0)
                sum += nums[left - 1];

            if(sum > x)
                break;

            int remaining = x - sum;

            if(remaining == 0){
                ans = min(ans, left);
            }
            else if(rightSum.count(remaining)){
                int rightCount = rightSum[remaining];

                // left and right portions must not overlap
                if(left + rightCount <= n){
                    ans = min(ans, left + rightCount);
                }
            }
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};