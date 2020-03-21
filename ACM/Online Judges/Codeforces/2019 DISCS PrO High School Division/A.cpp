#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

int n, m, k;
int store[27], ans[27];
string s, env;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    k %= 26;
    up(i, 1, n){
        cin >> s;
        up(i, 0, (int)s.size() - 1) ++store[s[i] - 'a' + 1];
    }
    up(i, 1, m) {
        cin >> env;
        memset(ans, 0, sizeof(ans));
        up(i, 0, (int)env.size() - 1) {
            int pos = env[i] - 'a' + 1 + k;
            if (pos > 26) pos -= 26;
            ++ans[pos];
        }
        up(i, 1, 26) {
            if (ans[i] > store[i]) {
                cout << "It is gonna be daijoubu." << endl;
                return 0;
            }
        }
    }
    cout << "Make her kokoro go doki-doki!";

    return 0;
}