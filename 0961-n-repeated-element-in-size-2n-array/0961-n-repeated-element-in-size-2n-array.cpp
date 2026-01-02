class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if (nums[0] == nums[1] || nums[0] == nums[2])
            return nums[0];
        if (nums[1] == nums[2])
            return nums[1];
        int n = nums.size(), res = -1, cnt = 0;
        for (int i = 3; i < n; i++) {
            if (cnt > 0) {
                if (res == nums[i])
                    cnt++;
                else
                    cnt--;
            } else {
                cnt++;
                res = nums[i];
            }
        }
        return res;
    }
};