class Solution {
public:
    void getallcombinations(vector<vector<int>>& combinations,vector<int>& ans,int n,int k,int idx){
        if(ans.size()==k){
            combinations.push_back(ans);
            return;
        }

        for(int i=idx;i<=n;i++){
            ans.push_back(i);
            getallcombinations(combinations,ans,n,k,i+1);
            ans.pop_back();
        }
    }

    vector<vector<int>> combine(int n,int k){
        vector<vector<int>> combinations;
        vector<int> ans;
        getallcombinations(combinations,ans,n,k,1);
        return combinations;
    }
};