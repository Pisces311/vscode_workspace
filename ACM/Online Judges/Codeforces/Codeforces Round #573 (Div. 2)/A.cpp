#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int x;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> x;
    if (x % 4 == 1) cout << 0 << ' ' << 'A' << endl;
    if (x % 4 == 3) cout << 2 << ' ' << 'A' << endl;
    if (x % 4 == 2) cout << 1 << ' ' << 'B' << endl;
    if (x % 4 == 0) cout << 1 << ' ' << 'A' << endl;

    return 0;
}