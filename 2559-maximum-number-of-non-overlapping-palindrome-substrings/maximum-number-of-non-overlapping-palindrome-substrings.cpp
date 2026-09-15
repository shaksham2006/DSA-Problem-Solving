class Solution {
public:

    bool isPallendromic(string& s, int left, int right){
        while(left<right){
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int count=0;
        int left=0;
        for(int right=0;right<s.size();right++){
            if(right-left+1<k)
                continue;
            for(int start=right-k+1;start>=left;start--){
                if(isPallendromic(s,start,right)){
                    count++;
                    left=right+1;
                    break;
                }
            }
        }
        return count;
    }
};