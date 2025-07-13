class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0, j = 0, count = 0;
        int n = players.size(), m = trainers.size();
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        while (i < n && j < m) {
            if (players[i] <= trainers[j]) count++, i++, j++;
            else j++;
        }
        return count;
    }
};