class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            int temp = i;
            int digpro = 1;

            while (temp > 0) {
                digpro *= (temp % 10);
                temp /= 10;
            }

            if (digpro % t == 0)
                return i;
        }

        return -1;
    }
};