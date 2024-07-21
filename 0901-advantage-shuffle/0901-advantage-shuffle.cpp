class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> unused;
        vector<int> result(n, -1);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums2[i], i});
        }
        sort(v.begin(), v.end());
        sort(nums1.begin(), nums1.end());
        for (int i = 0, j = 0; i < n; i++) {
            if (v[j].first < nums1[i]) {
                result[v[j++].second] = nums1[i];
            } else {
                unused.push_back(nums1[i]);
            }
        }
        for (int i = 0, j = 0; i < n; i++) {
            if (result[i] == -1) {
                result[i] = unused[j++];
            }
        }
        return result;
    }
};