class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int count = 0, n = fruits.size();
        unordered_map<int, int> mp;
        for (int i = 0, j = 0; i < n; i++) {
            mp[fruits[i]]++;
            while (mp.size() > 2) {
                mp[fruits[j]]--;
                if (mp[fruits[j]] == 0) {
                    mp.erase(fruits[j]);
                }
                j++;
            }
            count = max(count, i - j + 1);
        }
        return count;
    }
};