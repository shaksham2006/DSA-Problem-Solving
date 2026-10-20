class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // Try every possible block size k
        for (int k = 1; k <= n; k++) {
            // k must divide n
            if (n % k != 0) {
                continue;
            }
            bool valid = true;
            int prevMax = -1;
            // Process each block of size k
            for (int start = 0; start < n; start += k) {
                int mn = nums[start];
                int mx = nums[start];
                int descents = 0;
                // Check every element in this block
                for (int j = start; j < start + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                    // Find the next index, wrapping around
                    int next;
                    if (j + 1 == start + k) {
                        next = start;
                    } else {
                        next = j + 1;
                    }
                    // Count circular descents
                    if (nums[j] > nums[next]) {
                        descents++;
                    }
                }
                // Validate this block and its boundary
                if (descents > 1 || prevMax > mn) {
                    valid = false;
                    break;
                }
                // Save current block's maximum
                prevMax = mx;
            }
            // Add k if every block is valid
            if (valid) {
                ans += k;
            }
        }
        return ans;
    }
};
