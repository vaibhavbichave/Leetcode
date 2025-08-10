class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = nums.size(), n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] != i)
                k = min(k, nums[i] & i);
        return k == n ? 0 : k;
    }
};