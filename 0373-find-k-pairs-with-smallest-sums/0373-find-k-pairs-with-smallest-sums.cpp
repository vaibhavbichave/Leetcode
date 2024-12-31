class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> v;
        set<pair<int, int>> visited;
        typedef pair<int, pair<int, int>> pi;
        int n = nums1.size(), m = nums2.size();
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        while (k-- && !pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            v.push_back({nums1[r], nums2[c]});
            if (r + 1 < n && visited.find({r + 1, c}) == visited.end()) {
                visited.insert({r + 1, c});
                pq.push({nums1[r + 1] + nums2[c], {r + 1, c}});
            }
            if (c + 1 < m && visited.find({r, c + 1}) == visited.end()) {
                visited.insert({r, c + 1});
                pq.push({nums1[r] + nums2[c + 1], {r, c + 1}});
            }
        }
        return v;
    }
};