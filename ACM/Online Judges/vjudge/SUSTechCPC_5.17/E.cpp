#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 5e6 + 5;
constexpr int mod = 1e9 + 7;

struct TrieTreeNode {
    int son[2], cnt;
} trie[maxn];

int m, tot = 1;
int dp[3005][3005];
char s[maxn];

bool check(int i) {
    if (s[i - 3] == '0' && s[i - 2] == '0' && s[i - 1] == '1' && s[i] == '1')
        return false;
    if (s[i - 3] == '0' && s[i - 2] == '1' && s[i - 1] == '0' && s[i] == '1')
        return false;
    if (s[i - 3] == '1' && s[i - 2] == '1' && s[i - 1] == '1' && s[i] == '0')
        return false;
    if (s[i - 3] == '1' && s[i - 2] == '1' && s[i - 1] == '1' && s[i] == '1')
        return false;
    return true;
}

int insert(int l, int r) {
    int u = 1, ans = 0;
    for (int i = r; i >= l; --i) {
        int v = s[i] - '0';
        if (!trie[u].son[v]) trie[u].son[v] = ++tot;
        u = trie[u].son[v];
        dp[i][r] = dp[i][r - 1];
        if (r - i + 1 >= 2) dp[i][r] = (dp[i][r] + dp[i][r - 2]) % mod;
        if (r - i + 1 >= 3) dp[i][r] = (dp[i][r] + dp[i][r - 3]) % mod;
        if (r - i + 1 >= 4 && check(r))
            dp[i][r] = (dp[i][r] + dp[i][r - 4]) % mod;
        if (!trie[u].cnt) {
            trie[u].cnt = dp[i][r];
            ans = (ans + trie[u].cnt) % mod;
        }
    }
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;
    int ans = 0;
    for (int i = 1; i <= m; ++i) dp[i][i - 1] = dp[i][i] = 1;
    for (int i = 1; i <= m; ++i) {
        char ch;
        cin >> ch;
        s[i] = ch;
        ans = (ans + insert(1, i)) % mod;
        cout << ans << '\n';
    }

    return 0;
}