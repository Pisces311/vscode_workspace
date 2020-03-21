#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 4e7 + 5;

int T, N, M, Q, K;
int lst[maxn], pile[maxn];

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> M >> Q;
        for (int i = 1; i <= N; ++i) lst[i] = i + 1;
        int poke = 1, p = 1;
        pile[p] = poke;
        lst[N] = 2;
        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) p = lst[p];
            pile[lst[p]] = ++poke;
            lst[p] = lst[lst[p]];
        }
        while (Q--) {
            cin >> K;
            cout << pile[K] << '\n';
        }
    }

    return 0;
}