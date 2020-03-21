#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxc = 205;
const int maxn = 105;
const int maxq = 25;

int T, n, q, c, m;
int rsp[maxc][maxq];
int ans[maxn][maxq];
string name[maxc];
string tmp;
map<string, int> ma;

inline void init() {
    up(i, 1, c) mem(rsp, 0);
    ma.clear();
}

inline void sort_map() {
    up(i, 1, c) {
        cin >> name[i];
        ma[name[i]] = i;
    }
}

int found(int li) {
    bool first = true;
    int tmp;
    up(i, 1, c) {
        up(j, 1, q) {
            if (ans[li][j] != rsp[i][j])
                break;
            else if (j == q) {
                if (first) {
                    first = false;
                    tmp = i;
                } else
                    return 0;
            }
        }
    }
    if (!first) return tmp;
    return 0;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(T);
    while (T--) {
        scanf("%d %d", &n, &q);
        scan(c);
        init();
        sort_map();
        up(i, 1, q) {
            scan(m);
            up(j, 1, m) {
                cin >> tmp;
                map<string, int>::iterator ite = ma.find(tmp);
                rsp[ite->second][i] = 1;
            }
        }
        up(i, 1, n) up(j, 1, q) scan(ans[i][j]);
        up(i, 1, n) {
            int res = found(i);
            if (res != 0)
                cout << name[res] << endl;
            else
                cout << "Let's go to the library!!" << endl;
        }
    }

    return 0;
}