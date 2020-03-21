#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

int m, l, r, ans;
string a;

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    while (cin >> a) {
        cin >> m;
        int len = a.size();
        ans = 0;
        up(i, 1, m) {
            cin >> l >> r;
            ans += l - 1 + len - r;
        }
        if (ans & 1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }

    return 0;
}