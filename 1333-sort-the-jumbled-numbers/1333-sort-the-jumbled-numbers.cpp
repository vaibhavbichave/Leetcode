class Solution {
public:
    int convert(int x, vector<int>& mapping) {
        int val = 0;
        if (x == 0) return mapping[val];
        for (int pow10 = 1; x > 0; pow10 *= 10) {
            auto [q, r] = div(x, 10);
            val += mapping[r] * pow10;
            x = q;
        }
        return val;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int n = nums.size();
        vector<array<int, 3>> mapNum(n);
        for (int idx = 0; idx < n; idx++) {
            int x = nums[idx];
            mapNum[idx] = {convert(x, mapping), idx, x};
        }
        sort(mapNum.begin(), mapNum.end());
        for (int i = 0; i < n; i++) {
            nums[i] = mapNum[i][2];
        }
        return nums;
    }
};