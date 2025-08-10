class Solution {
public:
    vector<int> getList(int n) {
        vector<int> v(10, 0);
        while (n) {
            v[n % 10]++;
            n /= 10;
        }
        return v;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> l1 = getList(n);
        for (int i = 0; i < 31; i++) {
            vector<int> l2 = getList(1 << i);
            if (l1 == l2) return true;
        }
        return false;
    }
};