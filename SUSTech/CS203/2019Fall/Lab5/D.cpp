#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 5;

int T, n, tar;
int a[maxn];
bool in[maxn];
stack<int> slot;

inline void init() {
    tar = 1;
    while (slot.size()) slot.pop();
    memset(in, false, sizeof(in));
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
        init();
        cin >> n;
        for (int j = 1; j <= n; ++j) cin >> a[j];
        for (int j = 1; j <= n; ++j) {
            if (!slot.empty()) {
                if (slot.top() == tar) {
                    cout << slot.top() << ' ';
                    slot.pop();
                    ++tar;
                    --j;
                } else if (slot.top() < tar) {
                    cout << slot.top() << ' ';
                    slot.pop();
                    --j;
                } else if (in[tar]) {
                    ++tar;
                    --j;
                } else {
                    slot.push(a[j]);
                    in[a[j]] = true;
                }
            } else {
                slot.push(a[j]);
                in[a[j]] = true;
            }
        }
        while (slot.size()) {
            cout << slot.top() << ' ';
            slot.pop();
        }
        cout << '\n';
    }

    return 0;
}