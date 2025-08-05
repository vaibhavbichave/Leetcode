class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int x : nums) {
            if (st.contains(x))
                return true;
            st.insert(x);
        }
        return false;
    }
};