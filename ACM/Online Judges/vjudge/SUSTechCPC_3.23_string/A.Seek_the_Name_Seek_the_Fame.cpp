#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 4e5 + 5;

string s;
int n[maxn], ans[maxn], top;

void getNext() {
    n[0] = 0;
    for (int q = 1, k = 0; q < s.size(); q++) {
        while (k > 0 && s[q] != s[k])
            k = n[k - 1];
        if (s[q] == s[k])
            k++;
        n[q] = k;
    }
}

int main() {
#ifdef DEBUG
    freopen("D:\in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    while (cin >> s) {
        top = 0;
        getNext();
        if (n[s.size() - 1] != s.size())
            ans[++top] = s.size();
        int tmp = s.size() - 1;
        while (n[tmp] != 0) {
            ans[++top] = n[tmp];
            tmp = n[tmp - 1];
        }
        sort(ans + 1, ans + top + 1);
        up(i, 1, top) cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}