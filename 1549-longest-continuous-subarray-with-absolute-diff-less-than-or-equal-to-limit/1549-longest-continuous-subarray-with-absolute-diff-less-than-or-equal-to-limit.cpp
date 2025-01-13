class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int len = 0, n = nums.size();
        priority_queue<pair<int, int>> maxi;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            mini;
        for (int slow = 0, fast = 0; fast < n; fast++) {
            mini.push({nums[fast], fast});
            maxi.push({nums[fast], fast});
            while (maxi.top().first - mini.top().first > limit) {
                slow = min(maxi.top().second, mini.top().second) + 1;
                while (maxi.top().second < slow)
                    maxi.pop();
                while (mini.top().second < slow)
                    mini.pop();
            }
            len = max(len, fast - slow + 1);
        }
        return len;
    }
};