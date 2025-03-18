class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int usedBits = 0, start = 0, result = 0;
        for (int end = 0; end < nums.size(); end++) {
            while ((usedBits & nums[end]))
                usedBits ^= nums[start++];
            usedBits |= nums[end];
            result = max(result, end - start + 1);
        }
        return result;
    }
};