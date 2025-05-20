class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& qs) {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        for (auto x : qs) {
            v[x[0]]--;
            v[x[1] + 1]++;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            if (nums[i] + sum > 0)
                return false;
        }
        return true;
    }
};