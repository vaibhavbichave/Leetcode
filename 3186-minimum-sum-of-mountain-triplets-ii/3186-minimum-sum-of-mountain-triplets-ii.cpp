class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        vector<int> left(n, INT_MAX), right(n, INT_MAX);
        for (int i = 1; i < n; i++)
            left[i] = min(left[i - 1], nums[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            right[i] = min(right[i + 1], nums[i + 1]);
        for (int i = 1; i < n - 1; i++)
            if (left[i] < nums[i] && right[i] < nums[i])
                ans = min(ans, left[i] + nums[i] + right[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};