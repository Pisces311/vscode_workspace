#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int _max = 1e2 + 3;

int T, R, C, ans;
int ng[_max][_max];
char g[_max][_max];
bool vis[_max][_max], ok;

inline void init(){
    ans = 0;
    ok = true;
    up(i, 1, R) memset(vis[i], false, sizeof(vis[i]));
}

inline void get_g(){
    up(i, 1, R) up(j, 1, C) {
        switch (g[i][j]) {
            case '^':
                ng[i][j] = 1;
                break;
            case 'v':
                ng[i][j] = 2;
                break;
            case '<':
                ng[i][j] = 3;
                break;
            case '>':
                ng[i][j] = 4;
                break;
            default:
                ng[i][j] = 0;
                break;
        }
    }
}

void judge(){
    up(i, 1, R) {
        up(j, 1, C) {
            if (ng[i][j] != 0){
                if(accumulate(ng[i]+1, ng[i]+C+1, 0) == ng[i][j]){
                    int sum = 0;
                    up(k, 1, R) sum += ng[k][j];
                    if (sum == ng[i][j]) {
                        ok = false;
                        return;
                    }
                }
            }
        }
    }
}

void run(int x, int y){
    bool cont = true;
    bool found = false;
    while (cont) {
        found = false;
        switch (ng[x][y]) {
            case 1:
                for (x -= 1; x >= 1; --x) {
                    if (ng[x][y] != 0) {
                        if (vis[x][y]) return;
                        else{
                            vis[x][y] = true;
                            found = true;
                        }
                        break;
                    }
                }
                if (!found) {
                    ++ans;
                    cont = false;
                }
                break;
            case 2:
                for (x += 1; x <= R; ++x) {
                    if (ng[x][y] != 0) {
                        if (vis[x][y])
                            return;
                        else {
                            vis[x][y] = true;
                            found = true;
                        }
                        break;
                    }
                }
                if (!found){
                    ++ans;
                    cont = false;
                }
                break;
            case 3:
                for (y -= 1; y >= 1; --y) {
                    if (ng[x][y] != 0) {
                        if (vis[x][y])
                            return;
                        else {
                            vis[x][y] = true;
                            found = true;
                        }
                        break;
                    }
                }
                if (!found) {
                    ++ans;
                    cont = false;
                }
                break;
            case 4:
                for (y += 1; y <= C; ++y) {
                    if (ng[x][y] != 0) {
                        if (vis[x][y])
                            return;
                        else {
                            vis[x][y] = true;
                            found = true;
                        }
                        break;
                    }
                }
                if (!found) {
                    ++ans;
                    cont = false;
                }
                break;
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> T;
    up(k, 1, T) {
        cin >> R >> C;
        init();
        up(i, 1, R) cin >> g[i] + 1;
        get_g();
        judge();
        if(!ok){
            cout << "Case #" << k << ": IMPOSSIBLE" << endl;
            continue;
        }
        up(i, 1, R)up(j, 1, C)if(!vis[i][j] && ng[i][j]!=0){
            vis[i][j] = true;
            run(i, j);
        }
        cout << "Case #" << k << ": " << ans << endl;
    }

    return 0;
}