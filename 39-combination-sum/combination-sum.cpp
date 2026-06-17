class Solution {
public:
    set<vector<int>> s;
    void getAllCombinations(vector<int>& arr, int tar, int idx,vector<vector<int>> &ans,vector<int>&combin){
        if(idx== arr.size() || tar < 0) return;
        if(tar == 0){
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }   
        combin.push_back(arr[idx]); 
        //single inclusion
        getAllCombinations(arr,tar-arr[idx],idx+1,ans,combin);
        //multiple inclusion
        getAllCombinations(arr,tar-arr[idx],idx,ans,combin);
        //exclusion
        combin.pop_back();//backtracking
        getAllCombinations(arr,tar,idx+1,ans,combin);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<int>combin;
        vector<vector<int>> ans;
        getAllCombinations(arr,tar,0,ans,combin);
        return ans;
        
    }
};