class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            res = res ^ (i + 1) ^ nums[i];
        }
        return res;
    }
};