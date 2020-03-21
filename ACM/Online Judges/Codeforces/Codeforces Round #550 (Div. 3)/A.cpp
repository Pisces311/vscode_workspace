#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e2 + 5;

int n;
string s[maxn];
int cnt[27];

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) cin >> s[i];
    up(i, 1, n){
        int pos;
        bool flag1 = false, flag2 = false;
        bool ok = true;
        memset(cnt, 0, sizeof(cnt));
        up(j, 0, s[i].size() - 1) ++cnt[s[i][j] - 'a' + 1];
        up(j, 1, 26){
            if (cnt[j] == 1 && !flag2) flag1 = true;
            else if(cnt[j] == 0 && flag1)
                flag2 = true;
            else if(cnt[j]==0)
                continue;
            else
                ok = false;
        }
        if (ok) cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}