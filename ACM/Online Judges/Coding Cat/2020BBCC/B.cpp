#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e5 + 5;

struct node {
    int val, id;
    bool operator<(const node& a) const { return val < a.val; }
} f[maxn], s[maxn];

int n, m;
map<int, int> fmap, smap;

void deal(node* arr, map<int, int>& m) {
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; ++i) m[arr[i].id] = i;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i].val;
        f[i].id = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i].val;
        s[i].id = i;
    }
    deal(f, fmap);
    deal(s, smap);
    ll min0 = 0, max0 = 0;
    for (int i = 1; i <= n; ++i) {
        min0 += 1ll * f[i].val * s[n - i + 1].val;
        max0 += 1ll * f[i].val * s[i].val;
    }
    cout << min0 << ' ' << max0 << '\n';
    for (int i = 1; i <= m; ++i) {
        int ty, id, delta;
        cin >> ty >> id >> delta;
        if (ty == 1) {
            int newid = fmap[id];
            f[newid].val += 1;
            if (newid != n && f[newid].val > f[newid + 1].val) {
                swap(fmap[f[newid].id], fmap[f[newid + 1].id]);
                swap(f[newid], f[newid + 1]);
                ++newid;
            } else if (newid != 1 && f[newid].val < f[newid - 1].val) {
                swap(fmap[f[newid].id], fmap[f[newid - 1].id]);
                swap(f[newid], f[newid - 1]);
                --newid;
            }
            min0 += delta * s[n - newid + 1].val;
            max0 += delta * s[newid].val;
        } else {
            int newid = smap[id];
            s[newid].val += 1;
            if (newid != n && s[newid].val > s[newid + 1].val) {
                swap(smap[s[newid].id], smap[s[newid + 1].id]);
                swap(s[newid], s[newid + 1]);
                ++newid;
            } else if (newid != 1 && s[newid].val < s[newid - 1].val) {
                swap(smap[s[newid].id], smap[s[newid - 1].id]);
                swap(s[newid], s[newid - 1]);
                --newid;
            }
            min0 += delta * f[n - newid + 1].val;
            max0 += delta * f[newid].val;
        }
        cout << min0 << ' ' << max0 << '\n';
    }

    return 0;
}