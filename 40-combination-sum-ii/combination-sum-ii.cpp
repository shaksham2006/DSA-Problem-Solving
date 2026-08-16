class Solution {
public:
    void getAllCombinations(vector<int>& arr,int tar,int idx,vector<vector<int>>& ans,vector<int>& combin){
        if(tar==0){
            ans.push_back(combin);
            return;
        }

        if(idx==arr.size() || tar<0) return;

        for(int i=idx;i<arr.size();i++){
            if(i>idx&&arr[i]==arr[i-1]) continue;
            if(arr[i]>tar) break;

            combin.push_back(arr[i]);
            getAllCombinations(arr,tar-arr[i],i+1,ans,combin);
            combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr,int tar){
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombinations(arr,tar,0,ans,combin);
        return ans;
    }
};