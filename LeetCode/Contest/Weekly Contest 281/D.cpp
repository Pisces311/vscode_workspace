#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

    long long coutPairs(vector<int>& nums, int k) {
        vector<int> a(100005);
        for (int i : nums) a[i]++;
        vector<int> divisors;
        for (int i = 1; i <= k; i++)
            if (k % i == 0) divisors.push_back(i);
        map<int, int> sums;
        for (int i : divisors) {
            int tot = 0;
            for (int j = i; j <= 100000; j += i) tot += a[j];
            sums[i] = tot;
        }
        long long ans = 0;
        for (int i : nums) {
            int target = k / gcd(i, k);
            ans += sums[target];
        }
        for (int i : nums)
            if ((1ll * i * i) % k == 0) ans--;
        return ans / 2;
    }
};