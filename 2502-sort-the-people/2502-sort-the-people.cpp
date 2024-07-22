class Solution {
public:
    static bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({heights[i], names[i]});
        }
        sort(v.begin(), v.end(), cmp);
        vector<string> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = v[i].second;
        }
        return result;
    }
};