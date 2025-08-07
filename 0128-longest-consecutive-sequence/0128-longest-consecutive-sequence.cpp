class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxi = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for (int x : st) {
            if (!st.contains(x - 1)) {
                int len = 1;
                while (st.contains(x + len)) len++;
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};