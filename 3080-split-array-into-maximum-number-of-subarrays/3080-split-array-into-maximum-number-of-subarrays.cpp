class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0, curr = 0;
        for (int n : nums) {
            curr = (curr == 0) ? n : curr & n;
            res += (curr == 0);
        }
        return max(1, res);
    }
};