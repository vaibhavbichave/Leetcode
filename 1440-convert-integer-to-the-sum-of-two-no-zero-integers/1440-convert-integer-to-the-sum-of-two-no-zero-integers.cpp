class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto check = [](int x) -> bool {
            while (x) {
                if (x % 10 == 0)
                    return false;
                x /= 10;
            }
            return true;
        };
        for (int i = 1; i < n; i++)
            if (check(i) && check(n - i))
                return {i, n - i};
        return {};
    }
};