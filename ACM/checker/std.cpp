#include <bits/stdc++.h>

using namespace std;

#define IOO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'

typedef long long ll;

const int N = 1e6 + 10;
int prime[N];
inline void getPrime() {
	for (int i = 2; i < N; i++) {
		if (! prime[i]) prime[++prime[0]] = i;
		for (ll j = 1, k; j <= prime[0] && (k = 1ll * prime[j] * i) < 1ll * N; j++) {
			prime[k] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

const int S = 8;

ll quick_mul(ll a, ll b, ll c) {
	a %= c;
	b %= c;
	ll ret = 0, tmp = a;
	while (b) {
		if (b & 1) {
			ret += tmp;
			if (ret > c) ret -= c;
		}
		tmp <<= 1;
		if (tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}

ll quick_power(ll a, ll b, ll p) {
	ll x = 1;
	while (b) {
		if (b & 1) x = quick_mul(x, a, p);
		b >>= 1;
		a = quick_mul(a, a, p);
	}
	return x;
}

bool check(ll a, ll n, ll x, ll t) {
	ll ret = quick_power(a, x, n);
	ll last = ret;
	for (int i = 1; i <= t; i++) {
		ret = quick_mul(ret, ret, n);
		if (ret == 1 && last != 1 && last != n - 1) return 1;
		last = ret;
	}
	if (ret != 1) return 1;
	return 0;
}

bool Miller_Rabin(ll n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	if ((n & 1) == 0) return 0;
	ll x = n - 1;
	ll t = 0;
	while ((x & 1) == 0) {
		x >>= 1;
		t++;
	}
	srand(time(NULL));
	for (int i = 0; i < S; i++) {
		ll a = rand() % (n - 1) + 1;
		if (check(a, n, x, t)) return 0;
	}
	return 1;
}

ll gcd(ll a, ll b) {
	ll t;
	while (b) {
		t = a;
		a = b;
		b = t % b;
	}
	if (a >= 0) return a;
	else return -a;
}

ll pollard_rho(ll x, ll c) {
	ll i = 1, k = 2;
	srand(time(NULL));
	ll x0 = rand() % (x - 1) + 1;
	ll y = x0;
	while (1) {
		i++;
		x0 = (quick_mul(x0, x0, x) + c) % x;
		ll d = gcd(y - x0, x);
		if (d != 1 && d != x) return d;
		if (y == x0) return x;
		if (i == k) {
			y = x0;
			k += k;
		}
	}
}

ll factor[200];
int fcnt;

void findfactors(ll n, int k) {
	if (n == 1) return;
	if (Miller_Rabin(n)) {
		factor[++fcnt] = n;
		return;
	}
	ll p = n;
	int c = k;
	while (p >= n) p = pollard_rho(p, c--);
	findfactors(p, k);
	findfactors(n / p, k);
}

int T, ans;
ll n;

const double eps = 1e-6;

double cuberoot(double n) {
	double x = 1;
	while (1) {
		double nx = (x * 2.0 + n / x / x) / 3.0;
		if (fabs(x - nx) < eps) break;
		x = nx;
	}
	return x;
}

int main() {
	IOO;
	getPrime();
	for (cin >> T; T; T--) {
		cin >> n;
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		ans = N;
		for (int i = 1; i <= 1300; i++) {
			if (n % prime[i] == 0) {
				int temp = 0;
				while (n % prime[i] == 0) {
					n /= prime[i];
					temp++;
				}
				ans = min(ans, temp);
			}
		}
		if (n == 1 || ans == 1) {
			cout << ans << endl;
			continue;
		}
		ll r4 = (ll) sqrt(sqrt(n));
		if (r4 * r4 * r4 * r4 == n) ans = min(ans, 4);
		else {
			ll r2 = (ll) sqrt(n);
			if (r2 * r2 == n) ans = min(ans, 2);
			else {
				ll r3 = (ll) cuberoot(n);
				if (r3 * r3 * r3 == n) ans = min(ans, 3);
				else ans = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}