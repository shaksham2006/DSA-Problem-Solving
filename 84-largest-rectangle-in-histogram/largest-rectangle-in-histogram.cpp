class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);  // left smaller nearest
        vector<int> right(n, 0); // right smaller nearest
        stack<int> s;

        // Right smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Clear stack to reuse for Left smaller
        while (!s.empty()) s.pop();

        // Left smaller
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Calculate maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};
