class Solution {
public:
    int largestRectangleArea(vector<int>& heights, int j) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : heights[i]);
            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            maxArea = max(maxArea, largestRectangleArea(heights, i));
        }
        return maxArea;
    }
};
