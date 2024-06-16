class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long missing = 1, patches = 0, index = 0, size = nums.size();
        while (missing <= n) {
            if (index < size && nums[index] <= missing) {
                missing += nums[index];
                index++;
            } else {
                missing += missing;
                patches++;
            }
        }
        return patches;
    }
};