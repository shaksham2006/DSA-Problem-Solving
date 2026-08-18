class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int left=0;left<=nums.size()-k;left++){
            unordered_set<int> seen;

            for(int right=left;right<left+k;right++){
                seen.insert(nums[right]);
            }

            for(int num:seen){
                freq[num]++;
            }
        }

        int ans=-1;

        for(auto num:freq){
            if(num.second==1){
                ans=max(ans,num.first);
            }
        }

        return ans;
    }
};