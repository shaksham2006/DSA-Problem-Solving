class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //we are replacing the 0 to -1 and the calculating the prefix sum and comparing directly since then we will need the sum to be 0 and maxsubarray len will be fount as id there is some particular sum arived before it mean from it till now the sum is zero so it will be len between
        unordered_map<int, int> first;
        first[0] = -1;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                sum--;
            else
                sum++;

            if (first.find(sum) != first.end()) {
                ans = max(ans, i - first[sum]);
            } else {
                first[sum] = i;
            }
        }
        return ans;
    }
};