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

    void update(int o, int l, int r, int q, T k) {
        if (r < q || q < l) return;
        if (l == r && l == q) {
            val[o] += k;
            return;
        }
        int mid = (l + r) >> 1;
        update(lc(o), l, mid, q, k);
        update(rc(o), mid + 1, r, q, k);
        pushUp(o, l, r);
    }
};

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& i : a) cin >> i;
    segmentTree st(100005);
    int cur = 0;
    for (int i : a) {
        st.update(0, 0, 100005, i, 1);
        while (st.query(0, 0, 100005, cur + 1, 100000) >= cur + 1) cur++;
        cout << cur << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}