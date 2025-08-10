class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1, n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] != i)
                k = k & nums[i] & i;
        return k == -1 ? 0 : k;
    }
};