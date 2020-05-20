#include <iostream>
#include <set>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int n, op, x;
multiset<int> pet, adopter;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ll ans = 0;
    while (n--) {
        cin >> op >> x;
        if (op == 1) {
            if (pet.empty())
                adopter.insert(x);
            else {
                auto it = pet.lower_bound(x);
                if (it == pet.begin()) {
                    ans += *it - x;
                    pet.erase(it);
                } else if (it == pet.end()) {
                    ans += x - *(--it);
                    pet.erase(it);
                } else {
                    auto suf = it, pre = --it;
                    if (*suf - x >= x - *pre) {
                        ans += x - *pre;
                        pet.erase(pre);
                    } else {
                        ans += *suf - x;
                        pet.erase(suf);
                    }
                }
            }
        } else {
            if (adopter.empty())
                pet.insert(x);
            else {
                auto it = adopter.lower_bound(x);
                if (it == adopter.begin()) {
                    ans += *it - x;
                    adopter.erase(it);
                } else if (it == adopter.end()) {
                    ans += x - *(--it);
                    adopter.erase(it);
                } else {
                    auto suf = it, pre = --it;
                    if (*suf - x >= x - *pre) {
                        ans += x - *pre;
                        adopter.erase(pre);
                    } else {
                        ans += *suf - x;
                        adopter.erase(suf);
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}