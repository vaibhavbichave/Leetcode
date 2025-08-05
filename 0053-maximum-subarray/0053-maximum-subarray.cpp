class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0], sum = 0;
        for (int x : nums) {
            sum += x;
            maxi = max(maxi, sum);
            sum = sum < 0 ? 0 : sum;
        }
        return maxi;
    }
};