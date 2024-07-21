class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for (string x : logs) {
            if (x[0] == '.' && x[1] == '.') {
                if (count > 0) {
                    count--;
                }
            } else if (x[0] != '.') {
                count++;
            }
        }
        return count;
    }
};