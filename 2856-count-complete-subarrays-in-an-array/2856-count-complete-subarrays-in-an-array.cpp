class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int count = 0, n = nums.size();
        int uniq = unordered_set<int>(nums.begin(), nums.end()).size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                count += (st.size() == uniq);
            }
        }
        return count;
    }
};