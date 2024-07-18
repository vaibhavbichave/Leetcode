class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long first = nums[0], second = 0;
        for (int i = 1; i < n; i++) {
            first = max(first, second + nums[i]);
            second = max(second, first - nums[i]);
        }
        return max(first, second);
    }
};