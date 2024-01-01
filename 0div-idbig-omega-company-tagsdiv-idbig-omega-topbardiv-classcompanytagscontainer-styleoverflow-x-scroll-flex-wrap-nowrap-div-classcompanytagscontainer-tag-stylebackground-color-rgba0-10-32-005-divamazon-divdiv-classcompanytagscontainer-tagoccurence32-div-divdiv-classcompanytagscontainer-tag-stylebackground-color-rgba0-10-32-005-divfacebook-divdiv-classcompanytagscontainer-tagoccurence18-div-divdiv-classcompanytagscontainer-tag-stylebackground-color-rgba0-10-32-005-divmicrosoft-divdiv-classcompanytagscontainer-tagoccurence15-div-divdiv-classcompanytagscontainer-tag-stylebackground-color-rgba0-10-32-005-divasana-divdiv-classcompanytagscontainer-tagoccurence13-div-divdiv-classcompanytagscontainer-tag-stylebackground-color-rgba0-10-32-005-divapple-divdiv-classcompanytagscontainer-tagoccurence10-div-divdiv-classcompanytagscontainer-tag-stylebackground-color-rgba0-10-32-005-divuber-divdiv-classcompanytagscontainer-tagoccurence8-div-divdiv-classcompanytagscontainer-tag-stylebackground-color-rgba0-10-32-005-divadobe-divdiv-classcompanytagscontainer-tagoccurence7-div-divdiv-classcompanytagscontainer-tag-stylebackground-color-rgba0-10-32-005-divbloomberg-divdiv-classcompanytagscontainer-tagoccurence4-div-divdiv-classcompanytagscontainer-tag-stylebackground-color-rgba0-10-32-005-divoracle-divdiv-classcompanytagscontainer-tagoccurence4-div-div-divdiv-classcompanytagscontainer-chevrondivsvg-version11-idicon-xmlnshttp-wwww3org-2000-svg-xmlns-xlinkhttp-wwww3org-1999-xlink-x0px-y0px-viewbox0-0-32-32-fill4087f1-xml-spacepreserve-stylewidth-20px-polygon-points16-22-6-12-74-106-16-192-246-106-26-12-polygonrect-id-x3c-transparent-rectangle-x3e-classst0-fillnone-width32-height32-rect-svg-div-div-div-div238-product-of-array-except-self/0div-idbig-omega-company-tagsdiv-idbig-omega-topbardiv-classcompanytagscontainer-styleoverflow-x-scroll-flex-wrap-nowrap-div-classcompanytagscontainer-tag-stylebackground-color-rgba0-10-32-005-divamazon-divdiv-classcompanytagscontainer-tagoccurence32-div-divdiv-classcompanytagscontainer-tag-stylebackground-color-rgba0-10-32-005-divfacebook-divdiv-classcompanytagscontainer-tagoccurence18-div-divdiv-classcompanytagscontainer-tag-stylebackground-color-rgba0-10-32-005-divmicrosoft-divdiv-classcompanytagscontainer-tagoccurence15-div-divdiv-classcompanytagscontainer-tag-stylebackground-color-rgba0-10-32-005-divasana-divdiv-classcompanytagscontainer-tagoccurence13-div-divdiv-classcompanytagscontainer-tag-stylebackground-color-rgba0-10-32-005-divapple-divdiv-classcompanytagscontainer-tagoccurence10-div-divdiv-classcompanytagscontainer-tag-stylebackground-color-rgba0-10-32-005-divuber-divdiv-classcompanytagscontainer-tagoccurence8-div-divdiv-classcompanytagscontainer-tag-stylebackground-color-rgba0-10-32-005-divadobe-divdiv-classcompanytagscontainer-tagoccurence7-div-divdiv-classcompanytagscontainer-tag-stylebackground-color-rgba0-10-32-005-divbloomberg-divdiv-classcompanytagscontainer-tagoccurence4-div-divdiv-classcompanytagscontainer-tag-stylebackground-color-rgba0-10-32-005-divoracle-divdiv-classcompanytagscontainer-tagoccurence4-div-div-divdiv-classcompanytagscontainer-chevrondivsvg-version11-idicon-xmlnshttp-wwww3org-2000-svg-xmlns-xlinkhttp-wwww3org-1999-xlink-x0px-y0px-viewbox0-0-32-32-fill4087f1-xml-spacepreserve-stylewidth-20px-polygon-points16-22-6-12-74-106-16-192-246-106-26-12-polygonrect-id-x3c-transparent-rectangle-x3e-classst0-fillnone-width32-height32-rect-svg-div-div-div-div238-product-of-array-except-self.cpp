class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = nums[0], suffix = nums[n-1];
        vector<int> result(n,1);
        for(int i=1;i<n;i++){
            result[i] *= prefix;
            prefix *= nums[i];
        }
        for(int i=n-2;i>=0;i--){
            result[i] *= suffix;
            suffix *= nums[i];
        }
        return result;
    }
};