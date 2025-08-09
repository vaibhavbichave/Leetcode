class Solution {
public:
    int trap(vector<int>& height) {
        int result =0;
        int i = 0, j = height.size() - 1;
        int maxLeft = height[i], maxRight = height[j];
        while (i < j) {
            if(maxLeft <= maxRight){
                maxLeft = max(maxLeft, height[++i]);
                result += maxLeft - height[i];
            }else {
                maxRight = max(maxRight, height[--j]);
                result += maxRight-height[j];
            }
        }
        return result;
    }
};