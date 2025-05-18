class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int i = 1, n = words.size(), last = groups[0];
        vector<string> answer(1, words[0]);
        while (i < n) {
            while (i < n && last == groups[i])
                i++;
            if (i < n) {
                last = groups[i];
                answer.push_back(words[i++]);
            }
        }
        return answer;
    }
};