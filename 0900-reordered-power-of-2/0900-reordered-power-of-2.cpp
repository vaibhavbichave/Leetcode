class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> v(31, vector<int>(10, 0));
        for (int i = 0;i < 31; i++) {
            int curr = 1 << i;
            while (curr) {
                int rem = curr % 10;
                curr /= 10;
                v[i][rem]++;
            }
        }
        vector<int> vv(10, 0);
        while (n) {
            int rem = n % 10;
            n /= 10;
            vv[rem]++;
        }
        for (auto curr : v)
            if (curr == vv)
                return true;
        return false;
    }
};