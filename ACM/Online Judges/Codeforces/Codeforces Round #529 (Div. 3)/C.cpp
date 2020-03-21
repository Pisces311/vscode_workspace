#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxk = 2e6 + 5;

int n, k;
int ans[maxk], top = 0;

int power(int x, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) {
			res = res * x;
		}
		x = x * x;
		n >>= 1;
	}
	return res;
}

int main() {
#ifdef DEBUG
	freopen("D:\in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);

	cin >> n >> k;
	bitset<32> b1(n);
	if (b1.count() > k || n < k) {
		cout << "NO" << endl;
		return 0;
	}
	else cout << "YES" << endl;
	while (n) {
		int tmp = 0;
		while (power(2, tmp) <= n) {
			++tmp;
		}
		ans[++top] = power(2, tmp - 1);
		n -= ans[top];
	}
	int l = 1;
	int cnt = top;
	while (cnt != k) {
		if (ans[l] != 1) {
			ans[++top] = ans[l] / 2;
			ans[++top] = ans[l] / 2;
			++l;
			++cnt;
		}
		else {
			++l;
			ans[++top] = 1;
		}
	}
	up(i, l, top)cout << ans[i] << ' ';
	cout << endl;

	return 0;
}