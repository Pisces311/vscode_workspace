#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
   public:
    ll maximumBeauty(vector<int>& flowers, ll newFlowers, ll target, ll full,
                     ll partial) {
        int n = flowers.size();

        // 降序排列
        sort(flowers.begin(), flowers.end(),
             [&](int a, int b) { return a > b; });

        // 有多少个已经full了，pfull指向第一个没满的
        int pfull = 0;
        while (pfull < n && flowers[pfull] >= target) pfull++;

        // 如果能全种满
        ll lack = 0;
        for (int i = pfull; i < n; i++) {
            lack += target - flowers[i];
        }
        if (lack != 0 && newFlowers >= lack)
            return max(n * full, (n - 1) * full + (target - 1) * partial);

        vector<int> leq(100001);
        for (int i = 1, j = n - 1; i <= 100000; i++) {
            leq[i] = leq[i - 1];
            while (j >= 0 && flowers[j] <= i) {
                leq[i]++;
                j--;
            }
        }

        vector<ll> suf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + flowers[i];
        }

        ll cur = newFlowers, ans = pfull * full + flowers.back() * partial;
        for (int i = pfull; i < n; i++) {
            if (cur <= 0) break;
            ll l = flowers.back(), r = target - 1;
            while (l <= r) {
                ll mid = (l + r) / 2;
                ll num = min(leq[mid], n - i);
                ll tot = suf[n - num];
                ll need = num * mid - tot;
                if (need <= cur) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ll _min = l - 1;
            ans = max(ans, i * full + _min * partial);
            cur -= target - flowers[i];
        }
        return ans;
    }
};