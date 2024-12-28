class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0, n = word.size();
        vector<int> v(256, 0);
        vector<int> first(26, -1), last(26, 0);
        for (int i = 0; i < n; i++) {
            if ('a' <= word[i] && word[i] <= 'z')
                last[word[i] - 'a'] = i;
            if ('A' <= word[i] && word[i] <= 'Z' && first[word[i] - 'A'] == -1)
                first[word[i] - 'A'] = i;
            v[word[i]]++;
        }
        for (int i = 'a', j = 'A'; i <= 'z'; i++, j++) {
            if (last[i - 'a'] >= 0 && first[j - 'A'] >= 0 &&
                last[i - 'a'] <= first[j - 'A']) {
                if (v[i] > 0 && v[j] > 0) {
                    count++;
                }
            }
        }
        return count;
    }
};