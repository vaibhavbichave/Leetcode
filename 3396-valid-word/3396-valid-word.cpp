class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        bool set = false, set2 = false;
        if (n < 3)
            return false;
        for (char x : word) {
            if (x >= '0' && x <= '9') {
            } else if (x >= 'a' && x <= 'z') {
                if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                    set = true;
                } else {
                    set2 = true;
                }
            } else if (x >= 'A' && x <= 'Z') {
                if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
                    set = true;
                } else {
                    set2 = true;
                }

            } else {
                return false;
            }
        }
        return set && set2;
    }
};