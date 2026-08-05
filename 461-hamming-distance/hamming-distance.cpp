class Solution {
public:
    int hammingDistance(int x, int y) {
        int xr = x ^ y;
        int ans = 0;

        while (xr > 0) {
            ans += xr & 1;
            xr >>= 1;
        }

        return ans;
    }
};