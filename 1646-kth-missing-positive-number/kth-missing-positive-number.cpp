class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s;

        for (int val : arr) {
            s.insert(val);
        }

        int maxelement = *max_element(arr.begin(), arr.end());

        for (int i = 1; i <= maxelement; i++) {

            if (s.find(i) == s.end()) {
                k--;

                if (k == 0) {
                    return i;
                }
            }
        }

        // If kth missing number is greater than max element
        return maxelement + k;
    }
};