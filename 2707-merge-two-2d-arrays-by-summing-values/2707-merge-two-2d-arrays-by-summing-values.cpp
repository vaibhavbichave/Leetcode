class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> v;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while (i < n && j < m) {
            if (nums1[i][0] < nums2[j][0]) {
                v.push_back(nums1[i++]);
            } else if (nums1[i][0] > nums2[j][0]) {
                v.push_back(nums2[j++]);
            } else {
                v.push_back({nums1[i][0], nums1[i++][1] + nums2[j++][1]});
            }
        }
        while (i < n) {
            v.push_back(nums1[i++]);
        }
        while (j < m) {
            v.push_back(nums2[j++]);
        }
        return v;
    }
};