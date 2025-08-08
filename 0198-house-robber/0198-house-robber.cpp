class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = 0, curr = 0, next = 0;
        for (int i = 0; i < n; i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};