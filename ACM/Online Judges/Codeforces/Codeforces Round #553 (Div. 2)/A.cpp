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

int n;
string s;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> s;
    int ans = INT_MAX;
    up(i, 0, (int)s.size() - 4) {
        int cur = 0;
        cur = min(abs(s[i] - 'A'),
                  min(abs(s[i] - ('A' + 26)), abs(s[i] - ('A' - 26)))) +
              min(abs(s[i + 1] - 'C'),
                  min(abs(s[i + 1] - ('C' + 26)), abs(s[i + 1] - ('C' - 26)))) +
              min(abs(s[i + 2] - 'T'),
                  min(abs(s[i + 2] - ('T' + 26)), abs(s[i + 2] - ('T' - 26)))) +
              min(abs(s[i + 3] - 'G'),
                  min(abs(s[i + 3] - ('G' + 26)), abs(s[i + 3] - ('G' - 26))));
        ans = min(ans, cur);
    }
    cout << ans << endl;

    return 0;
}