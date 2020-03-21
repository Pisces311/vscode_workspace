#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T, n, k;
int per[maxn], pos[maxn], num[maxn << 2], f[maxn];

void pushUp(int o, int l, int r) { num[o] = max(num[o << 1], num[o << 1 | 1]); }

int find_max(int o, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return num[o];
    int mid = (l + r) >> 1;
    return max(find_max(o << 1, l, mid, ql, qr),
               find_max(o << 1 | 1, mid + 1, r, ql, qr));
}

void update(int o, int l, int r, int pos, int val) {
    if (r < pos || pos < l) return;
    if (pos <= l && r <= pos) {
        num[o] += val;
        return;
    }
    int mid = (l + r) >> 1;
    update(o << 1, l, mid, pos, val);
    update(o << 1 | 1, mid + 1, r, pos, val);
    pushUp(o, l, r);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> per[i];
            pos[per[i]] = i;
        }
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        memset(f, 0, sizeof(f));
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; ++i) {
            int p = pos[i];
            f[i] = f[find_max(1, 1, n, max(1, p - k), min(n, p + k))] + 1;
            update(1, 1, n, p, i);
        }
        for (int i = 1; i <= n; ++i) cout << f[i] << " \n"[i == n];
    }

    return 0;
}