class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }

private:
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });
        int furthestEnd = rectangles[0][dim + 2];
        int n = rectangles.size(), gapCount = 0;
        for (int i = 1; i < n; i++) {
            if (furthestEnd <= rectangles[i][dim])
                gapCount++;
            furthestEnd = max(furthestEnd, rectangles[i][dim + 2]);
        }
        return gapCount >= 2;
    }
};