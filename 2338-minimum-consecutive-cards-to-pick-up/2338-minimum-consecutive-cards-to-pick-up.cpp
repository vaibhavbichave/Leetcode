class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size(), mini = INT_MAX;
        map<int, int> mp, count;
        for (int i = 0; i < n; i++) {
            if (mp.contains(cards[i])) {
                mini = min(mini, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;
        }
        return mini != INT_MAX ? mini : -1;
    }
};