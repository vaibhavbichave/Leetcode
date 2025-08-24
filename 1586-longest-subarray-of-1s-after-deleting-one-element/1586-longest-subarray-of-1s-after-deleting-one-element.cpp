class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), zeroCount = 0;
        int start = 0, len = 0;
        for (int i = 0; i < n; i++) {
            zeroCount += (nums[i] == 0);
            while (zeroCount > 1)
                zeroCount -= (nums[start++] == 0);
            len = max(len, i - start);
        }
        return len;
    }
};