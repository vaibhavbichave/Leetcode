class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0, n = nums.size();
        for (int i = 0; i < k; i++)
            sum += nums[i];
        long long maxi = sum;
        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            maxi = max(maxi, sum);
        }
        return (double)maxi / k;
    }
};