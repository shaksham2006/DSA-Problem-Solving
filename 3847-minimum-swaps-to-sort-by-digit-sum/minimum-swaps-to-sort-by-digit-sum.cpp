
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // {digit sum, number, original index}
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < n; i++) {
            int digsum = 0;
            int x = nums[i];
            while (x > 0) {
                digsum += x % 10;
                x /= 10;
            }
            arr.push_back({digsum, nums[i], i});
        }
        // Sort by digit sum, then by number
        sort(arr.begin(), arr.end());
        // Count minimum swaps using cycles
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || get<2>(arr[i]) == i)
                continue;
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(arr[j]);
                cycleSize++;
            }
            if (cycleSize > 1)
                swaps += cycleSize - 1;
        }
        return swaps;
    }
};
