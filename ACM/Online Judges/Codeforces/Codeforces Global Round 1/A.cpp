#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define ite(i, a, b) for (int i = a; i <= b; ++i)

const int maxn = 1e5 + 1;

int b, k, cnt = 0;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);

    // freopen("D:\in.txt", "r", stdin);

    cin >> b >> k;
    ite(i, 1, k) {
        cin >> a[i];
        if (a[i] % 2 == 1) ++cnt;
    }
    if (b % 2 == 0) {
        if (a[k] % 2 == 0)
            cout << "even" << endl;
        else
            cout << "odd" << endl;
    } else {
        if (cnt % 2 == 0)
            cout << "even" << endl;
        else
            cout << "odd" << endl;
    }

    return 0;
}