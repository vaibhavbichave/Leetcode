class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        auto vowel = [](int x) {
            return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
        };
        for (char x : s)
            count += vowel(x);
        return count != 0;
    }
};