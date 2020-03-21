#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

struct node {
    int need, p;
};

int q, n;
ll k;
char a[maxn];
vector<node> moves;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--) {
        cin >> n >> k;
        cin >> (a + 1);
        moves.clear();
        int last = 1;
        for (int i = 1; i <= n; ++i)
            if (a[i] == '0') {
                moves.push_back({i - last, i});
                ++last;
            }
        int cnt = 0, pos = -1;
        for (node i : moves) {
            if (k >= i.need) {
                k -= i.need;
                ++cnt;
            } else {
                pos = i.p;
                break;
            }
        }
        if (pos != -1) {
            for (int i = 1; i <= cnt; ++i) cout << '0';
            for (int i = cnt + 1; i <= pos; ++i) {
                if (i == pos - k)
                    cout << '0';
                else
                    cout << '1';
            }
            for (int i = pos + 1; i <= n; ++i) cout << a[i];
            cout << '\n';
        } else {
            for (int i = 1; i <= last - 1; ++i) cout << '0';
            for (int i = last; i <= n; ++i) cout << '1';
            cout << '\n';
        }
    }

    return 0;
}