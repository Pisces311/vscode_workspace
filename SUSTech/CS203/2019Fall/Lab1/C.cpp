#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int T;
char A[15][5];

int id(int x) {
    if (strlen(A[x]) == 2) {
        if (A[x][0] == 'W') return 30 + '9' - A[x][1];
        if (A[x][0] == 'T') return 20 + '9' - A[x][1];
        if (A[x][0] == 'Y') return 10 + '9' - A[x][1];
    } else {
        if (A[x][0] == 'E') return 7;
        if (A[x][0] == 'S') return 6;
        if (A[x][0] == 'W') return 5;
        if (A[x][0] == 'N') return 4;
        if (A[x][0] == 'B') return 3;
        if (A[x][0] == 'F') return 2;
        if (A[x][0] == 'Z') return 1;
    }
}

bool cmp(int k, int j) {
    if (id(k) < id(j)) return true;
    return false;
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
        for (int i = 1; i <= 13; ++i) cin >> A[i];
        // selection sort
        for (int i = 1; i <= 12; ++i) {
            int k = i;
            for (int j = i + 1; j <= 13; ++j)
                if (cmp(k, j)) k = j;
            swap(A[i], A[k]);
        }
        for (int i = 1; i <= 13; ++i) cout << A[i] << ' ';
        cout << '\n';
    }

    return 0;
}