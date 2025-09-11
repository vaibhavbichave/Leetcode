class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [](char x) {
            return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
        };
        vector<int> index;
        vector<char> value;
        for (int i = 0; i < s.size(); i++)
            if (isVowel(tolower(s[i])))
                index.push_back(i), value.push_back(s[i]);
        sort(value.begin(), value.end());
        for (int i = 0; i < value.size(); i++)
            s[index[i]] = value[i];
        return s;
    }
};