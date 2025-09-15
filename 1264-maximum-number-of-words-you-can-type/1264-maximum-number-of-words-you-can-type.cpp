class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int result = 0;
        std::string word;
        std::stringstream ss(text);
        unordered_set<char> st(brokenLetters.begin(), brokenLetters.end());
        while (ss >> word) {
            bool flag = true;
            for (char x : word) {
                if (st.contains(x)) {
                    flag = false;
                    break;
                }
            }
            result += flag;
        }
        return result;
    }
};