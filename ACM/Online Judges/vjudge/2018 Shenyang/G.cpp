#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 6e3 + 5;
const int maxv = 1e7 + 5;

int T, n, m;
vector<pair<int, int> > v[maxv], record;
int mp[maxn][maxn];
ll lastans;
set<pair<int, int> > cnt;
int dir[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void init() {
    for (int i = 0; i <= 6000; ++i)
        for (int j = 0; j <= 6000; ++j)
            if (i * i + j * j <= 1e7)
                v[i * i + j * j].push_back(make_pair(i, j));
}

bool judge(int x, int y) {
    if (0 <= x && x <= 6000 && 0 <= y && y <= 6000) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ":\n";
        record.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            mp[x][y] = w;
            record.push_back(make_pair(x, y));
        }
        lastans = 0;
        for (int qq = 1; qq <= m; ++qq) {
            int op, x, y, w, k;
            cin >> op >> x >> y;
            x = (x + lastans) % 6000 + 1, y = (y + lastans) % 6000 + 1;
            if (op == 1) {
                cin >> w;
                mp[x][y] = w;
                record.push_back(make_pair(x, y));
            } else if (op == 2)
                mp[x][y] = 0;
            else if (op == 3) {
                cin >> k >> w;
                cnt.clear();
                for (auto i : v[k]) {
                    int dx = i.first, dy = i.second;
                    for (int j = 0; j < 4; ++j) {
                        int nx = dx * dir[j][0] + x;
                        int ny = dy * dir[j][1] + y;
                        if (judge(nx, ny) && mp[nx][ny] != 0)
                            cnt.insert(make_pair(nx, ny));
                    }
                }
                for (auto i : cnt) mp[i.first][i.second] += w;
            } else {
                cin >> k;
                cnt.clear();
                for (auto i : v[k]) {
                    int dx = i.first, dy = i.second;
                    for (int j = 0; j < 4; ++j) {
                        int nx = dx * dir[j][0] + x;
                        int ny = dy * dir[j][1] + y;
                        if (judge(nx, ny) && mp[nx][ny] != 0)
                            cnt.insert(make_pair(nx, ny));
                    }
                }
                ll ans = 0;
                for (auto i : cnt) ans += mp[i.first][i.second];
                cout << ans << '\n';
                lastans = ans;
            }
        }
        for (auto i : record) mp[i.first][i.second] = 0;
    }

    return 0;
}