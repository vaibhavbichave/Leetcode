class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> v;
        int n = words.size();
        for (int i = 0; i < n; i++) 
            if (words[i].contains(x)) 
                v.push_back(i);
        return v;
    }
};