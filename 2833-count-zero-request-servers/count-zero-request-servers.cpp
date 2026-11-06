class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});                     //TO stroe original indexs of the quieries
        }
        sort(q.begin(), q.end());
        vector<int> cnt(n + 1, 0);         //to have a check on queries we have already visited
        vector<int> ans(queries.size());
        int l = 0, r = 0;
        int active = 0;
        for(int i = 0; i < q.size(); i++) {
            int query = q[i].first;
            int originalIndex = q[i].second;
            while(r < logs.size() && logs[r][1] <= query) {
                int id = logs[r][0];
                if(cnt[id] == 0) active++;
                cnt[id]++;
                r++;
            }
            while(l < r && logs[l][1] < query - x) {
                int id = logs[l][0];
                cnt[id]--;
                if(cnt[id] == 0) active--;
                l++;
            }
            ans[originalIndex] = n - active;
        }
        return ans;
    }
};