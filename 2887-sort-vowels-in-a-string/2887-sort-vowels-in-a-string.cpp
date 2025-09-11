class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [](char x) {
            return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
        };
        int n = s.size(), c = 0;
        vector<int> mp(256, 0);
        for (int i = 0; i < n; i++)
            if (isVowel(tolower(s[i])))
                mp[s[i]]++;
        for (int i = 0; i < n; i++) {
            if (isVowel(tolower(s[i]))) {
                if (mp['A'] > 0)
                    s[i] = 'A', mp['A']--;
                else if (mp['E'] > 0)
                    s[i] = 'E', mp['E']--;
                else if (mp['I'] > 0)
                    s[i] = 'I', mp['I']--;
                else if (mp['O'] > 0)
                    s[i] = 'O', mp['O']--;
                else if (mp['U'] > 0)
                    s[i] = 'U', mp['U']--;
                else if (mp['a'] > 0)
                    s[i] = 'a', mp['a']--;
                else if (mp['e'] > 0)
                    s[i] = 'e', mp['e']--;
                else if (mp['i'] > 0)
                    s[i] = 'i', mp['i']--;
                else if (mp['o'] > 0)
                    s[i] = 'o', mp['o']--;
                else if (mp['u'] > 0)
                    s[i] = 'u', mp['u']--;
            }
        }
        return s;
    }
};