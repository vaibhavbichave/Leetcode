class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0;
        int last = nums[0], count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] & 1) != (last & 1)) {
                last = nums[i];
                count++;
            }
            if (nums[i] & 1)
                odd++;
            else
                even++;
        }
        return max(max(odd, even), count);
    }
};