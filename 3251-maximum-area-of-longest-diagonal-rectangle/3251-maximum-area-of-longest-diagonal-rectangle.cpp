class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area = 0, maxi = 0, n = dimensions.size();
        for (int i = 0; i < n; i++) {
            int x = dimensions[i][0] * dimensions[i][0] +
                    dimensions[i][1] * dimensions[i][1];
            if (maxi < x) {
                maxi = x;
                area = dimensions[i][0] * dimensions[i][1];
            } else if (maxi == x) {
                area = max(area, dimensions[i][0] * dimensions[i][1]);
            }
        }
        return area;
    }
};