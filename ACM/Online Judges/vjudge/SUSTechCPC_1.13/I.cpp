#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
string s[maxn];

ll cal(string s) {
    ll tot = 0, cnt = 0;
    for (char i : s) {
        if (i == 's')
            ++cnt;
        else
            tot += cnt;
    }
    return tot;
}

bool cmp(const string& a, const string& b) {
    string ab = a + b;
    string ba = b + a;
    return cal(ab) > cal(ba);
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    sort(s + 1, s + n + 1, cmp);
    string t = "";
    for (int i = 1; i <= n; ++i) t += s[i];
    cout << cal(t) << '\n';

    return 0;
}