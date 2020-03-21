#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int n;
ll d[60];

void insert(ll val) {
    for (ll i = 59; i >= 0; --i) {
        if (val & 1ll << i) {
            if (d[i])
                val ^= d[i];
            else {
                d[i] = val;
                break;
            }
        }
    }
}

bool check(ll val) {
    for (ll i = 59; i >= 0; --i) {
        if (val & 1ll << i) {
            if (d[i])
                val ^= d[i];
            else
                break;
        }
    }
    return val > 0;
}

// 求一个线性基能异或出的最大值
ll qmax() {
    ll ans = 0;
    for (ll i = 59; i >= 0; --i) ans = max(ans, ans ^ d[i]);
    return ans;
}

// 求一个线性基能异或出的最小值
ll qmin() {
    for (int i = 0; i <= 59; ++i)
        if (d[i]) return d[i];
    return 0;
}

void rebuild() {
    for (int i = 59; i >= 0; --i)
        for (int j = i - 1; j >= 0; --j)
            if (d[i] & 1ll << j) d[i] ^= d[j];
}

// 求一个线性基能异或出的第k小的值
ll Kth(ll k) {
    rebuild();
    int cnt = 0;
    for (int i = 0; i <= 59; i++)
        if (d[i]) ++cnt;
    if (cnt < n && k == 1) return 0;  //最小异或和为0的情况
    if (cnt < n) --k;
    if (k >= (1ll << cnt)) return -1;  //不存在第k小异或和
    ll ans = 0;
    for (int i = 0; i <= 59; ++i)
        if (d[i]) {
            if (k & 1) ans ^= d[i];
            k >>= 1;
        }
    return ans;
}

int main() { return 0; }