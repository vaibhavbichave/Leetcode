class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> hashmap;
        for (auto& single_point : points)
            hashmap[single_point[0]].insert(single_point[1]);
        int n = points.size(), minimum_area = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 != x2 && y1 != y2 && hashmap[x1].contains(y2) &&
                    hashmap[x2].contains(y1))
                    minimum_area =
                        min(minimum_area, abs(x1 - x2) * abs(y1 - y2));
            }
        }
        return minimum_area != INT_MAX ? minimum_area : 0;
    }
};