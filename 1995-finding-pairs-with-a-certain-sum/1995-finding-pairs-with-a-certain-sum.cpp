class FindSumPairs {
private:
    vector<int> v1, v2;
    unordered_map<int, int> mp;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1, v2 = nums2;
        for (int x : nums2)
            mp[x]++;
    }

    void add(int index, int val) {
        mp[v2[index]]--;
        v2[index] += val;
        mp[v2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int x : v1)
            res += mp[tot - x];
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */