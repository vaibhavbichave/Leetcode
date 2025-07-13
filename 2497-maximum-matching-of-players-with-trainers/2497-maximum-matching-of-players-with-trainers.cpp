class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int cnt = 0, n = players.size(), m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        for (int i = 0, j = 0; i < n && j < m; i++) {
            int curr = players[i];
            while (j < m && curr > trainers[j])
                j++;
            if (j < m && curr <= trainers[j])
                cnt++, j++;
        }
        return cnt;
    }
};