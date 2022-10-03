#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ex_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ll x1, y1;
        ll gcd = ex_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - floor(a / b) * y1;
        return gcd;
    }
}

// return distince solutions of ax = b (mod n)
vector<ll> congruence_equation(ll A, ll B, ll N) {
    A = A % N;
    B = B % N;
    ll u = 0, v = 0;
    ll d = ex_gcd(A, N, u, v);
    if (B % d != 0) return {};
    ll x0 = (u * (B / d)) % N;
    if (x0 < 0) x0 += N;
    vector<ll> ans;
    for (ll i = 0; i <= d - 1; i++) ans.push_back((x0 + i * (N / d)) % N);
    return ans;
}
