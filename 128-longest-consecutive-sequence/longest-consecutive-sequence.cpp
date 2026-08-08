class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        int maxCount = 0;

        // Loop through unique numbers only
        for (auto& p : freq) {
            int x = p.first;

            // x is the beginning of a sequence
            if (freq.find(x - 1) == freq.end()) {

                int count = 1;
                int current = x;

                while (freq.find(current + 1) != freq.end()) {
                    current++;
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};