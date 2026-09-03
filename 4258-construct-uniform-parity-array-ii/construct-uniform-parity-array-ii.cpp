class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool even=true;
        bool odd=true;
        int evencount=0;
        int oddcount=0;
        int minOdd=INT_MAX;
        int minEven=INT_MAX;

        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                even=false;
                oddcount++;
                minOdd=min(minOdd,nums1[i]);
            }else{
                odd=false;
                evencount++;
                minEven=min(minEven,nums1[i]);
            }
        }

        if(even==true || odd==true) return true;

        return minOdd<minEven;
    }
};
//For making any even to odd we need and odd smaller number and even to make any odd even we need to substract a smaller odd number so the smallest one which can we substract to make it must be odd.