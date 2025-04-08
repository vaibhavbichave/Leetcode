class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        unordered_set<int> seen;
        for (int i = n - 1; i >= 0; i--) {
            seen.insert(nums[i]);
            v[i] = seen.size();
        }
        if (seen.size() == n)
            return 0;
        for (int i = 1; 3 * i < n; i++) {
            if (v[i * 3] == (n - i * 3))
                return i;
        }
        return ((n + 2) / 3);
    }
};