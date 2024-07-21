class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freqOnY(3, 0), freqNotOnY(3, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < n / 2) {
                    if (i == j || i == (n - j - 1)) {
                        freqOnY[grid[i][j]]++;
                    } else {
                        freqNotOnY[grid[i][j]]++;
                    }
                } else {
                    if (j == n / 2)
                        freqOnY[grid[i][j]]++;
                    else {
                        freqNotOnY[grid[i][j]]++;
                    }
                }
            }
        }

        int ans = INT_MAX;
        int ycount = 3 * (n / 2) + 1;
        int nonYcount = n * n - ycount;
        for (int i = 0; i < 3; i++) {
            int toYmake = ycount - freqOnY[i];
            int toNonY = INT_MAX;
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    toNonY = min(toNonY, nonYcount - freqNotOnY[j]);
                }
            }
            ans = min(ans, toYmake + toNonY);
        }
        return ans;
    }
};