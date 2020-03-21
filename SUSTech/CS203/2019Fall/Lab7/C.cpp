#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e3 + 5;

int T, N;
int a[maxn], b[maxn];

void dfs(int al, int ar, int bl, int br) {
    for (int i = bl; i <= br; ++i) {
        if (a[al] == b[i]) {
            dfs(al + 1, al + i - bl, bl, i - 1);
            dfs(al + i - bl + 1, ar, i + 1, br);
            cout << b[i] << ' ';
            break;
        }
    }
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
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> a[i];
        for (int i = 1; i <= N; ++i) cin >> b[i];
        dfs(1, N, 1, N);
        cout << '\n';
    }

    return 0;
}