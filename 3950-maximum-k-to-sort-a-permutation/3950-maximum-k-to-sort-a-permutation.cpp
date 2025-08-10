class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = INT_MAX, n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] != i)
                k &= i;
        return k == INT_MAX ? 0 : k;
    }
};