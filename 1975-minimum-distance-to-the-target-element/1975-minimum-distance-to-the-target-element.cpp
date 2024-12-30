class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size(), i = start, j = start, cnt = 0;
        while (i >= 0 || j < n) {
            if (i >= 0 && nums[i--] == target)
                return cnt;
            if (j < n && nums[j++] == target)
                return cnt;
            cnt++;
        }
        return cnt;
    }
};