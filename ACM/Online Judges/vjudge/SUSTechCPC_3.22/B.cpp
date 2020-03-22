#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int N, M;
char words[55][2];
int _min = 0x3f3f3f3f;
int pos[30], ans[30];
int occupy[30][30];
int version = 0;

bool check(int num) {
    ++version;
    for (int i = 1; i <= M; ++i) {
        int x = words[i][0] - 'a' + 1, y = words[i][1] - 'a' + 1;
        if (x <= num && y <= num) {
            if (occupy[pos[x]][pos[y]] == version) return false;
            occupy[pos[x]][pos[y]] = version;
        }
    }
    return true;
}

void dfs(int cur, int tot) {
    if (cur > N) {
        if (_min > tot) {
            _min = tot;
            for (int i = 1; i < 30; ++i) ans[i] = pos[i];
        }
        return;
    }
    if (tot > _min) return;
    for (int i = 1; i <= tot; ++i) {
        pos[cur] = i;
        if (check(cur)) dfs(cur + 1, tot);
        pos[cur] = 0;
    }
    pos[cur] = tot + 1;
    if (check(cur)) dfs(cur + 1, tot + 1);
    pos[cur] = 0;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> words[i];
    }
    dfs(1, 0);
    cout << _min << '\n';
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (ans[j] == i) cout << (char)('a' + j - 1);
        }
        cout << '\n';
    }

    return 0;
}