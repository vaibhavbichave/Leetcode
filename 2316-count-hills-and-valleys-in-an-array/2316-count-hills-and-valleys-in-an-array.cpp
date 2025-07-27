class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int n = nums.size();
        int left = 0, count = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                count += (nums[i] > nums[left] && nums[i] > nums[i + 1]);
                count += (nums[i] < nums[left] && nums[i] < nums[i + 1]);
                left = i;
            }
        }
        return count;
    }
};