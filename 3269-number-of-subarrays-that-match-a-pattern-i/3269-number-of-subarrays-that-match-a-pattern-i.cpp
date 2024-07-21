class Solution {
public:
    bool isValid(vector<int>& nums, vector<int>& pattern, int idx, int size) {
        for (int j = 0; j < size; j++) {
            if ((pattern[j] == 1 && nums[idx + j] >= nums[idx + j + 1]) ||
                (pattern[j] == 0 && nums[idx + j] != nums[idx + j + 1]) ||
                (pattern[j] == -1 && nums[idx + j] <= nums[idx + j + 1])) {
                return false;
            }
        }
        return true;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int result = 0, n = nums.size(), m = pattern.size();
        for (int idx = 0; idx < n - m; idx++) {
            if (isValid(nums, pattern, idx, m)) {
                result++;
            }
        }
        return result;
    }
};