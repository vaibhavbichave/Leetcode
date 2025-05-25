class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int result = 0;
        unordered_map<string, int> mp;
        for (string& word : words) {
            string copy = word;
            reverse(word.begin(), word.end());
            if (mp[word] > 0) {
                mp[word]--;
                result += 4;
            } else {
                mp[copy]++;
            }
        }
        for (auto [word, count] : mp) {
            if (count > 0 && word[0] == word[1]) {
                result += 2;
                break;
            }
        }
        return result;
    }
};