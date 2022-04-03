#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool check(vector<int>& candies, int mid, long long k) {
        if (!mid) return true;
        long long res = 0;
        for (int i : candies) {
            res += i / mid;
        }
        return res >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = *max_element(candies.begin(), candies.end());
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(candies, mid, k)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
};