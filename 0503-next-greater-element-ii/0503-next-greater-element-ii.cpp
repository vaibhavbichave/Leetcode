class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int max_idx = 0, maxi = nums[0];
        stack<int> s;
        vector<int> v(n, -1);
        for (int i = 0; i < n; i++) if (nums[max_idx] < nums[i]) max_idx = i;
        for (int i = max_idx, j = 0; j < n; j++) {
            int index = (i - j + n) % n;
            while (!s.empty() && s.top() <= nums[index]) s.pop();
            if (!s.empty()) v[index] = s.top();
            s.push(nums[index]);
        }
        return v;
    }
};