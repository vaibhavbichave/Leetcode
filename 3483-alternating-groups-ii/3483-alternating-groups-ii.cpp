class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for (int i = 0; i < k - 1; i++) 
            colors.push_back(colors[i]);
        int length = colors.size();
        int count = 0, left = 0, right = 1;
        while (right < length) {
            if (colors[right] == colors[right - 1]) {
                left = right;
                right++;
            } else {
                right++;
                if (k <= (right - left)) {
                    count++;
                    left++;
                }
            }
        }

        return count;
    }
};