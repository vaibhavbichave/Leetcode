class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0, total = 0, cnt = 0, n = nums.size();
        for (int x : nums)
            sum += x;
        for (int i = 0; i < n - 1; i++) {
            total += nums[i];
            cnt += (sum - total) <= total;
        }
        return cnt;
    }
};