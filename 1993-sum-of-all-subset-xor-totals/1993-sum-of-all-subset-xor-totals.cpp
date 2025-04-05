class Solution {
public:
    int solve(int i, int xorsum, vector<int>& nums, int n) {
        if (i < n) {
            return solve(i + 1, xorsum ^ nums[i], nums, n) +
                   solve(i + 1, xorsum, nums, n);
        }
        return xorsum;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return solve(0, 0, nums, n);
    }
};