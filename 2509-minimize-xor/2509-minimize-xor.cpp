class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsNum1 = __builtin_popcount(num1);
        int setBitsNum2 = __builtin_popcount(num2);
        if (setBitsNum1 < setBitsNum2) {
            for (int bitPos = 0, bitsToAdd = 0;
                 bitsToAdd < setBitsNum2 - setBitsNum1; bitsToAdd++) {
                while ((num1 >> bitPos) & 1)
                    ++bitPos;
                num1 |= (1 << bitPos);
            }
            return num1;
        } else if (setBitsNum1 > setBitsNum2) {
            for (int bitsToRemove = 0; bitsToRemove < setBitsNum1 - setBitsNum2;
                 bitsToRemove++)
                num1 &= (num1 - 1);
            return num1;
        }
        return num1;
    }
};