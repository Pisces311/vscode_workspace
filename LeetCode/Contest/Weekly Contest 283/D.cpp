#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
   public:
    ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        for (int cas = 0; cas < 8; cas++) {
            vector<int> stk;
            stk.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++) {
                ll a = stk.back(), b = nums[i];
                ll GCD = gcd(a, b);
                if (GCD != 1) {
                    stk.back() = a / GCD * b;
                } else
                    stk.push_back(b);
            }
            nums = stk;
            reverse(nums.begin(), nums.end());
        }
        return nums;
    }
};