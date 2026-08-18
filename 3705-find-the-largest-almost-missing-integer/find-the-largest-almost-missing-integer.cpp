class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        int n=nums.size();
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        if(k==1){
            int ans=-1;
            for(auto num:freq){
                if(num.second==1){
                    ans=max(ans,num.first);
                }
            }
            return ans;
        }
        int ans=-1;
        if(freq[nums[0]]==1){
            ans=max(ans,nums[0]);
        }
        if(freq[nums[n-1]]==1){
            ans=max(ans,nums[n-1]);
        }
        return ans;
    }
};