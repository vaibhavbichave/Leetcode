class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {score[i][k], i};
        sort(v.begin(), v.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        });
        vector<vector<int>> answer(n);
        for (int i = 0; i < n; i++)
            answer[i] = score[v[i].second];
        return answer;
    }
};