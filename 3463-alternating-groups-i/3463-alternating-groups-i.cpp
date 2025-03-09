class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0, n = colors.size();
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        for (int i = 1; i <= n; i++) {
            if (colors[i - 1] != colors[i] && colors[i] != colors[i + 1]) {
                count++;
            }
        }
        return count;
    }
};