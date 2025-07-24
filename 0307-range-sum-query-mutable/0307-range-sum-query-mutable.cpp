class NumArray {
private:
    int n;
    vector<int> seg;
    void update(int idx, int tl, int tr, int point, int val) {
        if (tl == point && tr == point) {
            seg[idx] = val;
            return;
        }
        if (point > tr || point < tl)
            return;
        int mid = (tl + tr) / 2;
        update(2 * idx + 1, tl, mid, point, val);
        update(2 * idx + 2, mid + 1, tr, point, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    void build(vector<int>& a, int idx, int tl, int tr) {
        if (tl == tr) {
            seg[idx] = a[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        build(a, 2 * idx + 1, tl, mid);
        build(a, 2 * idx + 2, mid + 1, tr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    int query(int idx, int tl, int tr, int l, int r) {
        if (tl > r || tr < l)
            return 0;
        if (l <= tl && tr <= r)
            return seg[idx];
        int mid = (tl + tr) / 2;
        int left = query(2 * idx + 1, tl, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, tr, l, r);
        return left + right;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void update(int index, int val) { update(0, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object wiint be instantiated and cainted as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */