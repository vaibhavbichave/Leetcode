class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);
        for (char x : word) v[x - 'a']++;
        sort(v.begin(), v.end());

        int total = 0, count = 1;
        for (int i = 25; i >= 0; i--) {
            if ((25 - i) % 8 == 0 && i != 25) {
                count++;
            }
            total += count * v[i];
        }
        return total;
    }
};