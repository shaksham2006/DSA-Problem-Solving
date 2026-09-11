class Solution {
public:
    void countall(vector<int>& digits,int idx,int digit,vector<int>&used,
                  unordered_set<int>&ans){
        
        if(idx==3){
            if(digit%2==0)
                ans.insert(digit);
            return;
        }

        for(int i=0;i<digits.size();i++){
            if(used[i]) continue;
            if(idx==0 && digits[i]==0) continue;

            used[i]=1;
            countall(digits,idx+1,digit*10+digits[i],used,ans);
            used[i]=0;
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<int>used(digits.size(),0);
        unordered_set<int>ans;

        countall(digits,0,0,used,ans);

        return ans.size();
    }
};