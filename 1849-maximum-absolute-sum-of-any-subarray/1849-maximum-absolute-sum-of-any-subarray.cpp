class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = 0, sum = 0;
        for (int x : nums) {
            sum = max(0, sum + x);
            maxi = max(maxi, sum);
        }
        sum = 0;
        for (int x : nums) {
            sum = max(0, sum - x);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};