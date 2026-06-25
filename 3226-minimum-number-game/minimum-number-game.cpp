class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>arr;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i = 0; i<n; i = i+2){
            int a = nums.back();
            nums.pop_back();
            int b = nums.back();
            nums.pop_back();
            arr.push_back(b);
            arr.push_back(a);
        }
        return arr;
    }
};