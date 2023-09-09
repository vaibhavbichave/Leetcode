class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        for (int currentSum = 1; currentSum <= target; currentSum++) {
            for (int numIndex = 0; numIndex < n; numIndex++) {
                int currentNum = nums[numIndex];
                if (currentSum - currentNum >= 0) {
                    dp[currentSum] += dp[currentSum - currentNum];
                }
            }
        }
        return dp[target];
    }
};