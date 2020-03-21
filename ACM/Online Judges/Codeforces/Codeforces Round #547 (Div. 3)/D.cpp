#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1.5e5 + 5;

int n, top = 0;
string l, r;
queue<int> lvec[27], rvec[27];
pii ans[maxn];

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif

    cin >> n;
    cin >> l >> r;
    up(i, 0, n - 1) {
        if (l[i] != '?')
            lvec[l[i] - 'a' + 1].push(i + 1);
        else
            lvec[0].push(i + 1);
    }
    up(i, 0, n - 1) {
        if (r[i] != '?')
            rvec[r[i] - 'a' + 1].push(i + 1);
        else
            rvec[0].push(i + 1);
    }
    up(i, 1, 26) {
        while (lvec[i].size() && rvec[i].size()) {
            ans[++top] = make_pair(lvec[i].front(), rvec[i].front());
            lvec[i].pop();
            rvec[i].pop();
        }
    }
    up(i, 1, 26) {
        while (lvec[0].size() && rvec[i].size()) {
            ans[++top] = make_pair(lvec[0].front(), rvec[i].front());
            lvec[0].pop();
            rvec[i].pop();
        }
    }
    up(i, 1, 26) {
        while (lvec[i].size() && rvec[0].size()) {
            ans[++top] = make_pair(lvec[i].front(), rvec[0].front());
            lvec[i].pop();
            rvec[0].pop();
        }
    }
    while (lvec[0].size() && rvec[0].size()) {
        ans[++top] = make_pair(lvec[0].front(), rvec[0].front());
        lvec[0].pop();
        rvec[0].pop();
    }
    cout << top << endl;
    up(i, 1, top) cout << ans[i].first << ' ' << ans[i].second << endl;

    return 0;
}