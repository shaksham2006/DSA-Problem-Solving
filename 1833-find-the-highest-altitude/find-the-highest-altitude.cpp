class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int maxAltitude = 0;   // Starting altitude

        for (int i = 0; i < gain.size(); i++) {
            sum += gain[i];
            maxAltitude = max(maxAltitude, sum);
        }

        return maxAltitude;
    }
};