class Solution {
public:
    int getdigitsum(int x) {
        int sm = 0;
        while (x) {
            sm += x % 10;
            x = x / 10;
        }
        return sm;
    }
    int maximumSum(vector<int>& nums) {
        int i = 0, res = -1, n = nums.size();
        vector<pair<int, int>> v;
        for (int x : nums) v.push_back({getdigitsum(x), x});
        sort(v.begin(), v.end());
        while (i + 1 < n) {
            while (i + 1 < n && v[i].first == v[i + 1].first) {
                res = max(res, v[i].second + v[i + 1].second);
                i++;
            }
            i++;
        }
        return res;
    }
};