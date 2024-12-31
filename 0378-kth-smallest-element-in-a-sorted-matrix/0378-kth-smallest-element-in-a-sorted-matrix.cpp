class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        typedef pair<int, pair<int, int>> pi;
        int n = matrix.size(), m = matrix[0].size();
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({matrix[0][0], {0, 0}});
        matrix[0][0] = INT_MIN;
        while (--k && !pq.empty()) {
            int val = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if (r + 1 < n && matrix[r + 1][c] != INT_MIN) {
                pq.push({matrix[r + 1][c], {r + 1, c}});
                matrix[r + 1][c] = INT_MIN;
            }
            if (c + 1 < m && matrix[r][c + 1] != INT_MIN) {
                pq.push({matrix[r][c + 1], {r, c + 1}});
                matrix[r][c + 1] = INT_MIN;
            }
        }
        return pq.top().first;
    }
};