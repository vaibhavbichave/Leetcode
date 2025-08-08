class Solution {
public:
    bool isPossible(unordered_map<char, int>& countS,
                    unordered_map<char, int>& countT) {
        for (auto [key, val] : countT)
            if (countS[key] < val)
                return false;
        return true;
    }
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int start = 0, len = INT_MAX, n = s.size();
        unordered_map<char, int> countS, countT;
        for (char x : t)
            countT[x]++;
        for (int i = 0, j = 0; i < n; i++) {
            countS[s[i]]++;
            while (j <= i && isPossible(countS, countT)) {
                if ((i - j + 1) < len) {
                    start = j;
                    len = i - j + 1;
                }
                countS[s[j++]]--;
            }
        }
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};