class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (auto& row : grid)
            for (int num : row)
                arr.push_back(num);
        sort(arr.begin(), arr.end());
        int operations = 0, median = arr[arr.size() / 2];
        for (int num : arr) {
            int diff = abs(num - median);
            if (diff % x)
                return -1;
            operations += diff / x;
        }
        return operations;
    }
};