#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

vector<ll> fac;

void get(ll n) {
    fac.clear();
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fac.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fac.push_back(n);
}