class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for (char& x : columnTitle) {
            sum*=26;
            sum += (x - 'A' + 1);
        }
        return sum;
    }
};