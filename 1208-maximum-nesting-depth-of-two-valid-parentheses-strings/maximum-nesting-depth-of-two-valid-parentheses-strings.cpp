class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> depth;
        int count = 0;
        for(int i = 0; i < seq.size(); i++) {
            if(seq[i] == '(') {
                count++;
                depth.push_back(count);
            }
            else {
                depth.push_back(count);
                count--;
            }
        }
        vector<int> ans;
        for(int i = 0; i < depth.size(); i++) {
            if(depth[i] % 2 == 0) {
                ans.push_back(1);
            }
            else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};