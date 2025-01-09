class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), count = 0;
        for (string x : words) 
            count += n <= x.size() && x.substr(0, n) == pref;
        return count;
    }
};