class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        vector<bool> visited(26, false);
        for (int i = 0; i < n; i++) {
            int current = s[i] - 'a';
            if (!visited[current]) {
                distance[current] += (i + 1);
                visited[current] = true;
            } else {
                distance[current] -= i;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (visited[i] && distance[i] != 0) {
                return false;
            }
        }
        return true;
    }
};