class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        if (n & 1) v.push_back(0);
        int left = -1, right = 1;
        for (int i = 0; i < n / 2; i++) {
            v.push_back(left--);
            v.push_back(right++);
        }
        return v;
    }
};