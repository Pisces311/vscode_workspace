#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e3 + 5;

char s[maxn << 1];
vector<int> v;

bool check(int l, int r) {
    while (l < r) {
        if (s[l] == s[r]) {
            ++l;
            --r;
        } else
            return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> (s + 1);
    int len = strlen(s + 1);
    char tar = s[len];
    for (int i = 1; i <= len; ++i)
        if (s[i] == tar) v.push_back(i);
    int pos = -1;
    for (int i : v) {
        if (check(i, len)) {
            pos = i;
            break;
        }
    }
    cout << (s + 1);
    reverse(s + 1, s + pos);
    for (int i = 1; i < pos; ++i) cout << s[i];
    cout << '\n';

    return 0;
}