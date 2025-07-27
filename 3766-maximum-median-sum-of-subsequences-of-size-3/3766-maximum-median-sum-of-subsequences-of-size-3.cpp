class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size() / 3;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 2; n--; i -= 2)
            sum += nums[i];
        return sum;
    }
};