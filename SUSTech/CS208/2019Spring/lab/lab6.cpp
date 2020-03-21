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

const int maxn = 1e5 + 5;

int T, N;
int a[maxn];
bool ok;

inline void divide(int l, int r) {
    bool found = false;
    map<int, int> m;
    if (l >= r) return;
    up(i, l, r) m[a[i]]++;
    int last = l;
    up(i, l, r) if (m[a[i]] == 1) {
        found = true;
        divide(last, i - 1);
        last = i + 1;
    }
    if (!found)
        ok = false;
    else
        divide(last, r);
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        cin >> N;
        ok = true;
        up(i, 1, N) cin >> a[i];
        divide(1, N);
        cout << (ok ? "Yes" : "No") << endl;
    }

    return 0;
}