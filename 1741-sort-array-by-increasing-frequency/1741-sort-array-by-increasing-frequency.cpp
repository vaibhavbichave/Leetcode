class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size(), freq[201] = {0};
        for (int x : nums) {
            freq[x + 100]++;
        }

        sort(nums.begin(), nums.end(), [&](int x, int y) {
            if (freq[x + 100] == freq[y + 100])
                return x > y;
            return freq[x + 100] < freq[y + 100];
        });
        return nums;
    }
};