class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {

        int xr = 0;

        unordered_set<int> s;

        for(auto &x : nums) {

            s.insert(x);

            xr ^= x;
        }

        for(auto &y : s) {
            xr ^= y;
        }

        return xr;
    }
};