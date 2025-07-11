class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), maxi = -1, mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (mini < nums[i])
                maxi = max(maxi, nums[i] - mini);
            mini = min(mini, nums[i]);
        }
        return maxi;
    }
};