#include <bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

   public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> Map;
        for (int i = 0; i < rectangles.size(); i++) {
            pair<int, int> rate = make_pair(rectangles[i][0], rectangles[i][1]);
            int GCD = gcd(rate.first, rate.second);
            rate.first /= GCD;
            rate.second /= GCD;
            Map[rate]++;
        }
        long long ans = 0;
        for (auto i = Map.begin(); i != Map.end(); i++) {
            long long n = i->second;
            ans += n * (n - 1) / 2;
        }
        return ans;
    }
};