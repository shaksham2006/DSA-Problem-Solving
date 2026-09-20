class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int left = 0;
        int right = 0;
        bool start = false;
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] <= nums[i+1]) continue;
            if(!start) {
                left = i;
                start = true;
            }
            right = i+1;
        }
        if(!start) return 0;
        int mn = nums[left];
        int mx = nums[left];
        for(int i = left; i <= right; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        while(left > 0 && nums[left-1] > mn) {
            left--;
        }
        while(right < nums.size()-1 && nums[right+1] < mx) {
            right++;
        }
        return right - left + 1;
    }
};