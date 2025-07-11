class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int res = 0, n = nums.size();
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            while (!st.empty() && st.top().first < nums[i]) {
                count = max(count + 1, st.top().second);
                st.pop();
            }
            res = max(res, count);
            st.push({nums[i], count});
        }
        return res;
    }
};