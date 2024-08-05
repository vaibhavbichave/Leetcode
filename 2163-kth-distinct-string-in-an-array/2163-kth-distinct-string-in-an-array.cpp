class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (string x : arr)
            mp[x]++;
        for (string x : arr)
            if (mp[x] == 1 && --k == 0)
                return x;
        return "";
    }
};