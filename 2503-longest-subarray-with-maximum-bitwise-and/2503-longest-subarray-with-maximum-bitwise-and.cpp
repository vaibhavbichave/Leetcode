class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, len = 0, maxi = 0;
        for (int x : nums)
            maxi = max(x, maxi);
        for (int x : nums) {
            if ((maxi & x) == maxi) {
                len++;
                res = max(res, len);
            } else {
                len = 0;
            }
        }
        return max(res, 1);
    }
};