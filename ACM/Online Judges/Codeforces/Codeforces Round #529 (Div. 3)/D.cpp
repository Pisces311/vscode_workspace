#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e5 + 5;

int n, cnt = 0;
pii rem[maxn];

int main() {
#ifdef DEBUG
	freopen("D:\in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);

	cin >> n;
	if (n == 3) {
		cout << "1 2 3" << endl;
		return 0;
	}
	up(i, 1, n)cin >> rem[i].first >> rem[i].second;
	int cur = 1, f, s;
	cout << cur << ' ';
	++cnt;
	while (cnt != n) {
		f = rem[cur].first;
		s = rem[cur].second;
		if (rem[f].first != s && rem[f].second != s)cur = s;
		else cur = f;
		cout << cur << ' ';
		++cnt;
	}

	return 0;
}