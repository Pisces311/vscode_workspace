#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e2 + 5;

int T, n;
ll k;
ll length[maxn];
char tmp1[] = {"#COFFEE"}, tmp2[] = {"#CHICKEN"};

void dfs(int s, ll num) {
    if (s == 1) {
        cout << tmp1[num];
    } else if (s == 2) {
        cout << tmp2[num];
    } else if (s > 60 || num <= length[s - 2]) {
        dfs(s - 2, num);
    } else
        dfs(s - 1, num - length[s - 2]);
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    length[1] = 6, length[2] = 7;
    for (int i = 3; i <= 60; ++i) length[i] = length[i - 2] + length[i - 1];
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i <= 9; ++i) {
            if (n > 60 || k + i <= length[n]) dfs(n, k + i);
        }
        cout << '\n';
    }

    return 0;
}