class Solution {
public:
    int countCommas(int n) {
        int count = 0;
        if(n<4){
            return 0;
        }
        else if(n <= 100000){
            for(int i = 1000;i <=n;i++){
                count++;
            }
            return count;
        }else{
            for(int i = 1000000;i <= n; i++){
                count+=2;
            }
        }
        return count;
    }
};