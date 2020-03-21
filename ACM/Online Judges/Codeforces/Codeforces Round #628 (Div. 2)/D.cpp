#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

ll u, v;
bitset<62> bitu, bitv, tmp;
int cnt[62];
vector<ll> out;

ll parse() {
    tmp.reset();
    for (int i = 0; i < 62; ++i)
        if (cnt[i]) {
            tmp[i] = 1;
            cnt[i]--;
        }
    return tmp.to_ullong();
}

void solve() {
    if (u > v) {
        cout << "-1\n";
        return;
    }
    bitu = u, bitv = v;
    for (int i = 61; i >= 0; --i) {
        if (bitv[i]) {
            if (bitu[i])
                cnt[i] += 1;
            else {
                if (i == 0) {
                    cout << "-1\n";
                    return;
                }
                cnt[i - 1] += 2;
            }
        }
        if (bitu[i] && cnt[i] % 2 == 0) {
            if (i == 0) {
                cout << "-1\n";
                return;
            }
            if (cnt[i] == 0) {
                for (int j = i + 1; j < 61; ++j) {
                    if (cnt[j] >= 2) {
                        for (int k = j; k > i; --k) {
                            cnt[k] -= 2;
                            cnt[k - 1] += 4;
                        }
                        break;
                    }
                }
            }
            cnt[i]--;
            cnt[i - 1] += 2;
        }
    }
    ll ans;
    while (ans = parse()) out.push_back(ans);
    cout << out.size() << '\n';
    for (ll i : out) cout << i << ' ';
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> u >> v;
    solve();

    return 0;
}