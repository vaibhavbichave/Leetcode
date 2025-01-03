class Solution {
public:
    string reorganizeString(string s) {
        string result;
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for (char x : s)
            mp[x]++;
        for (auto x : mp)
            pq.push({x.second, x.first});
        while (pq.size() >= 2) {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();
            result += x.second;
            result += y.second;
            if (--x.first > 0) {
                pq.push({x.first, x.second});
            }
            if (--y.first > 0) {
                pq.push({y.first, y.second});
            }
        }
        if (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            result += x.second;
            if (--x.first > 0) {
                return "";
            }
        }
        return result;
    }
};