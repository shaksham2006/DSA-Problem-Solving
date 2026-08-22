class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;

        int sum = 0;
        int pro = 1;

        while(n > 0){
            sum += n % 10;
            pro *= n % 10;
            n /= 10;
        }

        return original % (sum + pro) == 0;
    }
};