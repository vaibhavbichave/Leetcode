class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sCount, tCount;
        for(char x: s) sCount[x]++;
        for(char x: t) tCount[x]++;
        return sCount == tCount;
    }
};