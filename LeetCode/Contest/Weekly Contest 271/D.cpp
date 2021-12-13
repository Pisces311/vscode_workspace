#include <bits/stdc++.h>
using namespace std;

template <class T = int>
class segmentTree {
    vector<T> val;

   public:
    segmentTree(int n) : val(vector<T>((n + 5) << 2)) {}

    int lc(int o) { return 2 * o + 1; }
    int rc(int o) { return 2 * o + 2; }

    void pushUp(int o, int l, int r) { val[o] = val[lc(o)] + val[rc(o)]; }

    T query(int o, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) return 0;
        if (ql <= l && r <= qr) return val[o];
        int mid = (l + r) >> 1;
        return (query(lc(o), l, mid, ql, qr) +
                query(rc(o), mid + 1, r, ql, qr));
    }

    void update(int o, int l, int r, int p, T k) {
        if (r < p || p < l) return;
        if (p <= l && r <= p) {
            val[o] += k;
            return;
        }
        int mid = (l + r) >> 1;
        update(lc(o), l, mid, p, k);
        update(rc(o), mid + 1, r, p, k);
        pushUp(o, l, r);
    }
};

class Solution {
   public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        segmentTree<int> tr(200005);
        for (auto i : fruits) {
            tr.update(0, 0, 200000, i[0], i[1]);
        }
        int ans = 0;
        for (auto i : fruits) {
            int p = i[0], l, r;
            if (p < startPos - k || p > startPos + k) continue;
            if (p <= startPos) {
                int d = startPos - p;
                l = p, r = startPos + (k - d) / 2;
            } else {
                int d = p - startPos;
                l = startPos - (k - d) / 2, r = p;
            }
            ans = max(ans, tr.query(0, 0, 200000, l, r));
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> v = {{2, 8}, {6, 3}, {8, 6}};
    Solution sol;
    cout << sol.maxTotalFruits(v, 5, 4) << endl;
    return 0;
}