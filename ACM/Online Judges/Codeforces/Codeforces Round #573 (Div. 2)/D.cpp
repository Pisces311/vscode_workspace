#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n;
int pile[maxn];
ll take = 0;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> pile[i];
    }
    sort(pile + 1, pile + n + 1);
    int same = 0, pos;
    for (int i = 2; i <= n; ++i) {
        if (pile[i] == pile[i - 1]) {
            ++same;
            pos = i - 1;
        }
    }
    if (same > 1) {
        cout << "cslnb" << endl;
        return 0;
    }
    if (same == 1) {
        if (pile[pos] == 0 || (pos != 1 && pile[pos] - 1 == pile[pos - 1])) {
            cout << "cslnb" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        take += pile[i] - (i - 1);
    }
    if (take & 1)
        cout << "sjfnb" << endl;
    else
        cout << "cslnb" << endl;

    return 0;
}