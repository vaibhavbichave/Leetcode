class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        for(int i=0;i<nums.size();i++) pq.push({nums[i], i});
        vector<int> v;
        while(k--) v.push_back(pq.top().second), pq.pop();
        sort(v.begin(), v.end());
        for(int &x:v) x = nums[x];
        return v;
    }
};