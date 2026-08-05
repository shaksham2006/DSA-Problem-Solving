class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int flips = 0;

        while (diff > 0) {
            flips += diff & 1;
            diff >>= 1;
        }

        return flips;
    }
};