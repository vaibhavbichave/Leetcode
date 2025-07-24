class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int maxi = 0, result = 0;
        unordered_set<char> st({'a', 'e', 'i', 'o', 'u'});
        for (int i = 0; i < k; i++)
            result += st.contains(s[i]);
        maxi = max(maxi, result);
        for (int i = k; i < n; i++) {
            result -= st.contains(s[i - k]);
            result += st.contains(s[i]);
            maxi = max(maxi, result);
        }
        return maxi;
    }
};