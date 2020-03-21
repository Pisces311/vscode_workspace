#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 1e5 + 5;

int n;
int a[maxn];

int main() {
#ifdef DEBUG
	freopen("D:\in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);

	cin >> n;
	up(i, 1, n)cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << min(a[n] - a[2], a[n - 1] - a[1]) << endl;

	return 0;
}