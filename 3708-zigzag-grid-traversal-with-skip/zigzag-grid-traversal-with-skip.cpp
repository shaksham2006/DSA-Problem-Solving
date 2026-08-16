class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {

        vector<int> ans;
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {

            if (i % 2 == 0) {

                // left → right
                for (int j = 0; j < grid[0].size(); j++) {

                    if (count % 2 == 0)
                        ans.push_back(grid[i][j]);

                    count++;
                }

            } else {

                // right → left
                for (int j = grid[0].size() - 1; j >= 0; j--) {

                    if (count % 2 == 0)
                        ans.push_back(grid[i][j]);

                    count++;
                }
            }
        }

        return ans;
    }
};