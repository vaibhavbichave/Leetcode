class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), mini = s.size();
        int count_a = 0, count_b = 0;
        for (int i = 0; i < n; i++)
            count_a += (s[i] == 'a');
        for (int i = 0; i < n; i++) {
            count_a -= (s[i] == 'a');
            mini = min(mini, count_a + count_b);
            count_b += (s[i] == 'b');
        }
        return mini;
    }
};