class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int inc = 0, dec = 0;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;
            if (nums[i] > nums[next])
                inc++;
            if (nums[i] < nums[next])
                dec++;
        }
        if (inc == 1) {
            int i = 0;
            while (nums[i] != 0)
                i++;
            if (i == 0)
                return 0;
            return min(i, n - i + 2);
        }
        if (dec == 1) {
            int i = 0;
            while (nums[i] != 0)
                i++;
            return min(i + 2, n - i);
        }
        return -1;
    }
};