class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) v.push_back({profits[i], capital[i]});
        sort(v.begin(), v.end(), cmp);
        priority_queue<pair<int, int>> pq;
        for (int i = 0, j = 0; i < k; i++) {
            while (j < n && v[j].second <= w) pq.push(v[j++]);
            if (pq.empty()) break;
            w += pq.top().first;
            pq.pop();
        }
        return w;
    }
};