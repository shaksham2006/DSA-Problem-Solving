class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {

        vector<int> ans;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {

            for(int j = i + 1; j < nums.size(); j++) {

                if(nums[i] == nums[j]) {

                    count++;

                    nums.erase(nums.begin() + j); // erase larger index first
                    nums.erase(nums.begin() + i);

                    i--;      // adjust i
                    break;    // vector changed
                }
            }
        }

        ans.push_back(count);
        ans.push_back(nums.size());

        return ans;
    }
};