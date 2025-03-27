class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, dominant = 0;
        for (int num : nums) {
            dominant = (cnt == 0) ? num : dominant;
            cnt += (num == dominant) ? 1 : -1;
        }
        int total_dominant = count(nums.begin(), nums.end(), dominant);
        for (int i = 0, local_dominant = 0; i < n; i++) {
            local_dominant += (nums[i] == dominant);
            if (local_dominant * 2 > (i + 1) &&
                ((total_dominant - local_dominant) * 2 > (n - i - 1)))
                return i;
        }
        return -1;
    }
};