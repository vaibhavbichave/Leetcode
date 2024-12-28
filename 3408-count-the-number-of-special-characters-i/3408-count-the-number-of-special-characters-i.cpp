class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        vector<int> v(256, 0);
        for (auto x : word) v[x]++;
        for (int i = 'a', j = 'A'; i <= 'z'; i++, j++) {
            if (v[i] > 0 && v[j] > 0) {
                count++;
            }
        }
        return count;
    }
};