class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, maxi = 0, n = nums.size();
        while (i < n) {
            int prev = i, curr = i + 1, len = 1;
            while ((curr < n) && ((nums[prev] + 1) == nums[curr])) {
                while (curr + 1 < n && nums[curr] == nums[curr + 1])
                    curr++;
                len++;
                prev = curr;
                curr = curr + 1;
            }
            maxi = max(maxi, len);
            i = curr;
        }
        return maxi;
    }
};