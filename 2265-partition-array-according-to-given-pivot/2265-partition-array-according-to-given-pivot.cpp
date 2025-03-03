class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>v;
        for(int x:nums) if(x<pivot) v.push_back(x);
        for(int x:nums) if(x==pivot) v.push_back(x);
        for(int x:nums) if(x>pivot) v.push_back(x);
        return v;
    }
};