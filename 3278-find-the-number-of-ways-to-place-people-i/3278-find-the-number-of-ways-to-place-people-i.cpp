class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto x, auto y) {
            if (x[0] == y[0])
                return x[1] < y[1];
            return x[0] > y[0];
        });
        int count = 0 , n = points.size();
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX, curr = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int next = points[j][1];
                if (next >= curr && mini > next) {
                    count++;
                    mini = next;
                }
            }
        }
        return count;
    }
};