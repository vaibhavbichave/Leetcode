class Solution {
public:
    string getString(long long n, unordered_map<long long, char>& rev,
                     long long len) {
        string s;
        while (n) {
            len /= 10;
            s += rev[n / len];
            n %= len;
        }
        return s;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, long long> mp = {
            {'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
        unordered_map<long long, char> rev = {
            {1, 'A'}, {2, 'C'}, {3, 'G'}, {4, 'T'}};
        long long n = s.size(), len = 10000000000;
        unordered_map<long long, long long> store;
        for (long long i = 0, key = 0; i < n; i++) {
            key = 10 * key + mp[s[i]];
            key %= len;
            if (i >= 9)
                store[key]++;
        }
        vector<string> v;
        for (auto [key, count] : store) {
            if (count > 1)
                v.push_back(getString(key, rev, len));
        }
        return v;
    }
};