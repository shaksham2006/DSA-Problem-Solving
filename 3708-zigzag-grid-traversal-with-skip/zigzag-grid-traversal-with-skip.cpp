class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {

        vector<int> ans;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {

                for (int j = 0; j < m; j++) {
                    int pos = i * m + j;

                    if (pos % 2 == 0) {
                        ans.push_back(grid[i][j]);
                    }
                }

            } else {

                for (int j = m - 1; j >= 0; j--) {
                    int pos = i * m + (m - 1 - j);

                    if (pos % 2 == 0) {
                        ans.push_back(grid[i][j]);
                    }
                }
            }
        }

        return ans;
    }
};