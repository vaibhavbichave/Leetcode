class Solution {
public:
    bool solve(string& s) {
        char x = s[0], y = s[s.size() - 1];
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            if (y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u') {
                return true;
            }
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> v(1, 0);
        for (auto& x : words) {
            solve(x) ? v.push_back(v.back() + 1) : v.push_back(v.back());
        }
        vector<int> ans;
        for (auto x : queries)
            ans.push_back(v[x[1] + 1] - v[x[0]]);
        return ans;
    }
};