class Solution {
public:
    vector<int> arrayChange(vector<int>& nums,
                            vector<vector<int>>& operations) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;
        for (auto operation : operations) {
            nums[mp[operation[0]]] = operation[1];
            mp[operation[1]] = mp[operation[0]];
            mp.erase(operation[0]);
        }
        return nums;
    }
};