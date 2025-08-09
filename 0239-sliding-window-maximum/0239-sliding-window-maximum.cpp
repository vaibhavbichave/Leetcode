
class SegTree {
private:
    int n;
    vector<int> seg;
    void build(vector<int>& a, int idx, int tl, int tr) {
        if (tl == tr) {
            seg[idx] = a[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        build(a, 2 * idx + 1, tl, mid);
        build(a, 2 * idx + 2, mid + 1, tr);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    int query(int idx, int tl, int tr, int l, int r) {
        if (tl > r || tr < l)
            return INT_MIN;
        if (l <= tl && tr <= r)
            return seg[idx];
        int mid = (tl + tr) / 2;
        int left = query(2 * idx + 1, tl, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, tr, l, r);
        return max(left, right);
    }

public:
    SegTree(vector<int>& a) {
        n = a.size();
        seg.resize(4 * n);
        build(a);
    }
    SegTree(int len) { n = len; }
    void build(vector<int>& a) { build(a, 0, 0, n - 1); }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        SegTree seg(nums);
        for (int i = k; i <= nums.size(); i++)
            v.push_back(seg.query(i - k, i - 1));
        return v;
    }
};
