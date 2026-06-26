class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        unordered_map<int,int> freq;

        for(int i=0;i<nums.size();i++){

            int x = nums[i];      // Save value

            freq[x]++;

            if(freq[x] > 2){
                nums.erase(nums.begin()+i);
                freq[x]--;        // Use saved value
                i--;
            }
        }

        return nums.size();
    }
};