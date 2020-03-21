#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2017;

int T, n;
char a[maxn][maxn];
vector<int> p[maxn], q[maxn];

bool judge() {
    up(i, 1, n) up(j, i + 1, n) {
        if (a[i][j] == 'P') {
            for (int k : p[j])
                if (a[i][k] != 'P') return false;
        } else if (a[i][j] == 'Q') {
            for (int k : q[j])
                if (a[i][k] != 'Q') return false;
        } else if (a[j][i] == 'P') {
            for (int k : p[i])
                if (a[j][k] != 'P') return false;
        } else {
            for (int k : q[j])
                if (a[j][k] != 'Q') return false;
        }
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> n;
        up(i, 1, n) p[i].clear();
        up(i, 1, n) q[i].clear();
        up(i, 1, n) up(j, 1, n) {
            cin >> a[i][j];
            if (a[i][j] == 'P')
                p[i].push_back(j);
            else if (a[i][j] == 'Q')
                q[i].push_back(j);
        }
        cout << (judge() ? 'T' : 'N') << endl;
    }

    return 0;
}