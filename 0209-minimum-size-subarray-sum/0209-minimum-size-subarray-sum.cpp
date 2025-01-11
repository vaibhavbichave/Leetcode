class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0;
        int l = 0, r = 0, len = INT_MAX;
        while (r < n) {
            sum += nums[r++];
            while (target <= sum) {
                len = min(len, r - l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};