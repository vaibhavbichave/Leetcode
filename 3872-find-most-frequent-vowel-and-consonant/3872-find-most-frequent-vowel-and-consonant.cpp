class Solution {
public:
    int maxFreqSum(string s) {
        auto vowel = [](char x) {
            return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
        };
        int maxi1 = 0, maxi2 = 0;
        unordered_map<char, int> mp1, mp2;
        for (char x : s) {
            if (vowel(x)) 
                maxi1 = max(maxi1, ++mp1[x]);
            else 
                maxi2 = max(maxi2, ++mp2[x]);
        }
        return maxi1 + maxi2;
    }
};