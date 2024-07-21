class Solution {
    void getCount(string str, char first, char second, int& cnt1, int& cnt2) {
        int i = 1, n = str.size();
        while (i < n) {
            if (i > 0 && str[i - 1] == first && str[i] == second) {
                cnt1++;
                str.erase(i - 1, 2);
                n -= 2;
                i--;
            } else {
                i++;
            }
        }

        int j = 1, m = str.size();
        while (j < m) {
            if (j > 0 && str[j - 1] == second && str[j] == first) {
                cnt2++;
                str.erase(j - 1, 2);
                m -= 2;
                j--;
            } else {
                j++;
            }
        }
        return;
    }

public:
    int maximumGain(string s, int x, int y) {
        int mxABcnt = 0, mxBAcnt = 0;
        int minBAcnt = 0, minABcnt = 0;
        getCount(s, 'a', 'b', mxABcnt, minBAcnt);
        getCount(s, 'b', 'a', mxBAcnt, minABcnt);
        return max(mxABcnt * x + minBAcnt * y, mxBAcnt * y + minABcnt * x);
    }
};