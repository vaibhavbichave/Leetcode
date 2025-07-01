class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1, n = word.size();
        for (int i = 0; i < n - 1; i++)
            count += (word[i] == word[i + 1]);
        return count;
    }
};