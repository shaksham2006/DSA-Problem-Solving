class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int bit = 0; bit < 32; bit++) {
            int bitCount = 0;

            for (int num : nums)
                bitCount += (num >> bit) & 1;

            if (bitCount % 3)
                result |= (1 << bit);
        }

        return result;
    }
};