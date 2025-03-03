class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (auto i : nums)
            if (st.find(i) == st.end())
                st.insert(i);
            else
                return true;
        return false;
    }
};