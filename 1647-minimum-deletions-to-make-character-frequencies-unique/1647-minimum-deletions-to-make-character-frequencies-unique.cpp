class Solution {
public:
    int minDeletions(string s) {
        int deletions = 0;
        unordered_set<int> st;
        unordered_map<char, int> mp;  
        for (char x : s) mp[x]++;
        for (auto x : mp) {
            int freq = x.second;
            while (freq > 0 && st.find(freq) != st.end()) {
                freq--; deletions++;
            }
            st.insert(freq);
        } 
        return deletions;
    }
};