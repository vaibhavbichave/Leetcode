class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        vector<priority_queue<int>> pq(n + 1);
        for (int i = 0; i < n; i++)
            pq[limit[i]].push(value[i]);
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i && !pq[i].empty(); j++) {
                sum += 1ll * pq[i].top();
                pq[i].pop();
            }
        }
        return sum;
    }
};