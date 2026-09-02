class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool even = true;
        bool odd = true;
        int evencount = 0;
        int oddcount = 0;
        for(int i = 0; i < nums1.size();i++){
            if(nums1[i]%2!=0){
                even = false;
                oddcount++;
                continue;
            }else{
                odd = false;
                evencount++;
                continue;
            }
        }
        if(even == true || odd == true) return true;
        int evenrep = 0;
        int oddrep = 0;
        for(int i = 0; i < nums1.size();i++){
            for(int j = i+1; j < nums1.size(); j++){
                if((nums1[i]-nums1[j])%2==0){
                    evenrep++;
                }else{
                    oddrep++;
                }
            }
        }
        if(min(evencount,oddcount)<=max(evenrep,oddrep)) return true;
        return false;

    }
};