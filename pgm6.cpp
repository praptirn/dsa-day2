#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 0, 0, n-1);
    }

    void build(vector<int>& arr, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2*idx+1, l, mid);
        build(arr, 2*idx+2, mid+1, r);
        tree[idx] = max(tree[2*idx+1], tree[2*idx+2]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return INT_MIN;
        if (ql <= l && r <= qr) return tree[idx];

        int mid = (l + r) / 2;
        return max(
            query(2*idx+1, l, mid, ql, qr),
            query(2*idx+2, mid+1, r, ql, qr)
        );
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree st(arr);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(0, 0, n-1, l, r) << endl;
    }

    return 0;
}
