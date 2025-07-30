class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 1, len = 0, maxi = 0;
        for (int x : nums)
            maxi = max(x, maxi);
        for (int x : nums) {
            len = ((maxi & x) == maxi) ? len + 1 : 0;
            res = max(res, len);
        }
        return res;
    }
};