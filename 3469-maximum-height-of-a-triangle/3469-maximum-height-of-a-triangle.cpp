class Solution {
public:
    int f(int red, int blue) {
        int level = 1, flag = 1;
        while (red > 0 || blue > 0) {
            if (flag && red - level >= 0)
                red -= level++;
            else if (!flag && blue - level >= 0)
                blue -= level++;
            else
                break;
            flag ^= 1;
        }
        return level - 1;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(f(red, blue), f(blue, red));
    }
};