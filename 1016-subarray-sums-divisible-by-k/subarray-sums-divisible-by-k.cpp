class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        vector<int> freq(k, 0);
        // Prefix sum = 0 has appeared once
        freq[0] = 1;
        for (int num : nums) {
            sum += num;
            int rem = sum % k;
            // Handle negative remainder
            if (rem < 0) {
                rem += k;
            }
            // Every previous same remainder
            // forms a valid subarray
            count += freq[rem];
            freq[rem]++;
        }
        return count;
    }
};