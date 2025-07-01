class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1, n = word.size();
        for (int i = 0; i < n; i++) {
            int base = i;
            while (i + 1 < n && word[base] == word[i + 1]) i++;
            count += (i - base);
        }
        return count;
    }
};