class Solution {
public:
    int countEven(int num) {
        int count = 0;

        for(int i = 1; i <= num; i++) {
            int digsum = 0;
            int temp = i;

            while(temp > 0) {
                digsum += temp % 10;
                temp /= 10;
            }

            if(digsum % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};