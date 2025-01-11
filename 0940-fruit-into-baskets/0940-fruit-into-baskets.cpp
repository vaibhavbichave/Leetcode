class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), len = 0;
        unordered_map<int, int> mp;
        for (int j = 0, i = 0; i < n; i++) {
            mp[fruits[i]]++;
            while (mp.size() > 2) {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0) {
                    mp.erase(fruits[j]);
                }
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};