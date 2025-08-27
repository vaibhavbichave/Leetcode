class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), mini = INT_MAX;
        vector<int> prefix(n, 0), suffix(n, 0);
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + (s[i - 1] == 'b');
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + (s[i + 1] == 'a');
        for (int i = 0; i < n; i++)
            mini = min(mini, prefix[i] + suffix[i]);
        return mini;
    }
};