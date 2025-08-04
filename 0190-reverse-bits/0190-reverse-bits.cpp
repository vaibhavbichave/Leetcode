class Solution {
public:
    int reverseBits(int n) {
        int value, result = 0;
        for (int i = 0; i < 32; i++) {
            value = n & (1 << i);
            result |= value > 0 ? (1 << (31 - i)) : 0;
        }
        return result;
    }
};