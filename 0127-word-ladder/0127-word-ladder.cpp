class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        queue<pair<string, int>> q;
        q.emplace(beginWord, 1);
        while (!q.empty()) {
            auto [str, pathLen] = q.front();
            q.pop();
            if (str == endWord)
                return pathLen;
            int len = str.size();
            for (int i = 0; i < len; i++) {
                char original = str[i];
                for (char x = 'a'; x <= 'z'; x++) {
                    str[i] = x;
                    if (st.contains(str)) {
                        st.erase(str);
                        q.emplace(str, pathLen + 1);
                    }
                }
                str[i] = original;
            }
        }
        return 0;
    }
};