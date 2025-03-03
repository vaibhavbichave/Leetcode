class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        for (i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        for (i = 0; i < n; i++) {
            if (nums[i] > 0) {
                nums[j++] = nums[i];
            }
        }
        while (j < n) nums[j++] = 0;
        return nums;
    }
};