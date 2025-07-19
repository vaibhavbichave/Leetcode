class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> v;
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++)
            mp[nums[i]]++;
        for (int i = 0; i < n; i++) {
            if (i - k - 1 >= 0)
                mp[nums[i - k - 1]]--;
            if (i + k < n)
                mp[nums[i + k]]++;
            if (mp[key] > 0)
                v.push_back(i);
        }
        return v;
    }
};