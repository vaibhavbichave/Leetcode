class Solution {
public:
    int minimumLength(string s) {
        int sum = 0;
        vector<int> v(26, 0);
        for (char chr : s) v[chr - 'a']++;
        for (int x : v)
            if (x > 2) sum += (x & 1) ? 1 : 2;
            else sum += x;
        return sum;
    }
};