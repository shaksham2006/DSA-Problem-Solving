class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int freq[1001] = {0};
        vector<int> ans;

        for (auto& arr : nums) {
            for (int num : arr) {
                freq[num]++;
            }
        }

        for (int num = 0; num <= 1000; num++) {
            if (freq[num] == nums.size()) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};