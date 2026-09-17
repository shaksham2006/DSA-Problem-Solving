class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prelen(n, INT_MAX);
        vector<int> sufflen(n, INT_MAX);
        // Prefix: 0 se i tak ka shortest target subarray
        int left = 0;
        int sum = 0;
        int minprelen = INT_MAX;
        for(int right = 0; right < n; right++) {
            sum += arr[right];
            while(sum > target) {
                sum -= arr[left];
                left++;
            }
            if(sum == target) {
                minprelen = min(minprelen, right - left + 1);
            }
            prelen[right] = minprelen;
        }
        // Suffix: i se n-1 tak ka shortest target subarray
        int right = n - 1;
        sum = 0;
        int minsufflen = INT_MAX;
        for(int left = n - 1; left >= 0; left--) {
            sum += arr[left];
            while(sum > target) {
                sum -= arr[right];
                right--;
            }
            if(sum == target) {
                minsufflen = min(minsufflen, right - left + 1);
            }
            sufflen[left] = minsufflen;
        }
        // Prefix aur suffix ko non-overlapping combine karo
        int ans = INT_MAX;
        for(int i = 1; i < n; i++) {
            if(prelen[i-1] != INT_MAX && sufflen[i] != INT_MAX) {
                ans = min(ans, prelen[i-1] + sufflen[i]);
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};