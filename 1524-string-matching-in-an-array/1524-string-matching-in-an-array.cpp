class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> v;
        sort(words.begin(), words.end(),
             [&](string& a, string& b) { return a.size() < b.size(); });
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[j].find(words[i]) != -1) {
                    v.push_back(words[i]);
                    break;
                }
            }
        }
        return v;
    }
};