class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& nums, int& target, int sum,
              int index) {
        if (nums.size() == index)
            return target == sum;
        if (dp[index][sum + 1000] != -1)
            return dp[index][sum + 1000];
        int result = solve(dp, nums, target, sum + nums[index], index + 1) +
                     solve(dp, nums, target, sum - nums[index], index + 1);
        return dp[index][sum + 1000] = result;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2001, -1));
        return solve(dp, nums, target, 0, 0);
    }
};