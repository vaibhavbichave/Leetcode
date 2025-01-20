class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0), col(m, 0);
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mp[mat[i][j]] = {i, j};
        for (int k = 0; k < arr.size(); k++) {
            auto [i, j] = mp[arr[k]];
            row[i]++, col[j]++;
            if (row[i] == m || col[j] == n) 
                return k;
        }
        return arr.size();
    }
};