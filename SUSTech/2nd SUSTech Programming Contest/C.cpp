#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e3 + 5;

int n, m;
string perm[maxn];
char ans[maxn];

int rint(int a, int b) { return (rand() % (b - a + 1)) + a; }

bool check_front(int i, int j) {
    for (int k = 0; k <= n / 2; ++k) {
        if (perm[i][k] != perm[j][k]) return false;
    }
    for (int k = 0; k <= n / 2; ++k) ans[k] = perm[i][k];
    return true;
}

bool check_back(int i, int j) {
    for (int k = n / 2 + 1; k < n; ++k) {
        if (perm[i][k] != perm[j][k]) return false;
    }
    for (int k = n / 2 + 1; k < n; ++k) ans[k] = perm[i][k];
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));
    cin >> n >> m;
    int len = n - m + 1;
    for (int i = 1; i <= len; ++i) cin >> perm[i];
    random_shuffle(perm + 1, perm + len + 1);
    bool front = false, back = false;
    for (int i = 1; i <= len; ++i) {
        for (int j = i + 1; j <= len; ++j) {
            if (check_front(i, j)) {
                front = true;
                break;
            }
        }
        if (front) break;
    }
    for (int i = 1; i <= len; ++i) {
        for (int j = i + 1; j <= len; ++j) {
            if (check_back(i, j)) {
                back = true;
                break;
            }
        }
        if (back) break;
    }
    cout << ans << '\n';

    return 0;
}