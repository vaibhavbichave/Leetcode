class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int i = 1, n = nums.size();
        while (i < n - 1) {
            int prev = nums[i - 1];
            int curr = nums[i];
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
            if (i + 1 < n) {
                int next = nums[i + 1];
                if (prev < curr && next < curr)
                    count++;
                if (prev > curr && next > curr)
                    count++;
            }
            i++;
        }
        return count;
    }
};