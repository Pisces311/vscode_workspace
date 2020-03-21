#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

int n, ans = 0;
string s;

int main() {
#ifdef DEBUG
	freopen("D:\in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);

	cin >> n >> s;
	string rs(s.rbegin(), s.rend()); // to create a string in order to calculate the prefix
	up(i, 0, n - 1) {
		if (rs[i] == '(')rs[i] = ')';
		else rs[i] = '(';
	}
	vector<int> pref(n + 1), suf(n + 1);
	vector<bool> okp(n + 1), oks(n + 1);
	okp[0] = oks[n] = true;
	up(i, 0, n - 1) {
		pref[i + 1] = pref[i] + (s[i] == '(' ? +1 : -1);
		okp[i + 1] = okp[i] & (pref[i + 1] >= 0);
		suf[n - i - 1] = suf[n - i] + (rs[i] == '(' ? +1 : -1);
		oks[n - i - 1] = oks[n - i] & (suf[n - i - 1] >= 0);
	}
	up(i, 0, n - 1) {
		if (!okp[i] || !oks[i + 1])continue;
		if (s[i] == '(') {
			if (pref[i] > 0 && pref[i] - 1 - suf[i + 1] == 0)++ans;
		}
		else {
			if (pref[i] + 1 - suf[i + 1] == 0)++ans;
		}
	}
	cout << ans << endl;

	return 0;
}