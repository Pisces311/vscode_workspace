#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e2 + 5;

int T;
char s[maxn];
int kb[60];
bool vis[30];

bool check() {
    int len = strlen(s + 1);
    int p = 30;
    kb[p] = s[1] - 'a' + 1;
    vis[s[1] - 'a' + 1] = true;
    for (int i = 2; i <= len; ++i) {
        int l = p - 1, r = p + 1;
        int num = s[i] - 'a' + 1;
        if (vis[num]) {
            if (kb[l] == num)
                p = l;
            else if (kb[r] == num)
                p = r;
            else
                return false;
        } else {
            vis[num] = true;
            if (kb[l] == 0) {
                kb[l] = num;
                p = l;
            } else if (kb[r] == 0) {
                kb[r] = num;
                p = r;
            } else
                return false;
        }
    }
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
        memset(kb, 0, sizeof(kb));
        memset(vis, false, sizeof(vis));
        cin >> (s + 1);
        if (check()) {
            cout << "YES\n";
            for (int i = 0; i <= 59; ++i)
                if (kb[i]) cout << char('a' - 1 + kb[i]);
            for (int i = 1; i <= 26; ++i)
                if (!vis[i]) cout << char('a' - 1 + i);
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}