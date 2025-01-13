class Solution {
public:
    int minimumLength(string s) {
        int totalLength = 0;
        unordered_map<char, int> mp;
        for (char x : s) mp[x]++;
        for (auto [chr, frequency] : mp)
            if (frequency > 0)
                totalLength += (frequency & 1) ? 1 : 2;
        return totalLength;
    }
};