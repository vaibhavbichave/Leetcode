class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<long long, long long>> helper;
        for (long long x : nums) {
            long long original = x, val = 0, base = 1;
            while (x) {
                int map = mapping[x % 10];
                val = base * map + val;
                base *= 10;
                x /= 10;
            }
            if (original == 0) {
                helper.push_back({mapping[x], original});
            } else {
                helper.push_back({val, original});
            }
        }
        sort(helper.begin(), helper.end(),
             [&](pair<long long, long long> a, pair<long long, long long> b) {
                 return a.first < b.first;
             });

        vector<int> result;
        for (auto x : helper) {
            result.push_back(x.second);
        }
        return result;
    }
};