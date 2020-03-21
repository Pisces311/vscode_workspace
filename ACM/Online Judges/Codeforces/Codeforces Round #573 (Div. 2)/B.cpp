#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

string a, b, c;

bool string_cmp(string x, string y) {
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] != y[i]) return false;
    }
    return true;
}

bool check(string x, string y, string z) {
    string a[] = {x, y, z};
    sort(a, a + 3);
    if (a[0][1] == a[1][1] && a[0][1] == a[2][1]) {
        if (a[0][0] + 1 == a[1][0] && a[0][0] + 2 == a[2][0]) return true;
    }
    return false;
}

bool conti(string x, string y) {
    if ((x[1] == y[1]))
        if (x[0] + 1 == y[0] || x[0] + 2 == y[0]) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    cin >> a >> b >> c;
    int cnt = 0, ans1;
    if (string_cmp(a, b)) ++cnt;
    if (string_cmp(b, c)) ++cnt;
    if (string_cmp(a, c)) ++cnt;
    if (cnt == 3) {
        cout << 0 << endl;
        return 0;
    }
    if (cnt == 1) ans1 = 1;
    if (!cnt) ans1 = 2;
    int ans2;
    if (check(a, b, c)) {
        cout << 0 << endl;
        return 0;
    }
    string arr[] = {a, b, c};
    sort(arr, arr + 3);
    if (conti(arr[0], arr[1]) || conti(arr[1], arr[2]) || conti(arr[0], arr[2]))
        ans2 = 1;
    else
        ans2 = 2;
    cout << min(ans1, ans2) << endl;

    return 0;
}