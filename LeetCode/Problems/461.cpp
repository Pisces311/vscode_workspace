#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int hammingDistance(int x, int y) {
        bitset<35> a(x), b(y);
        int cnt = 0;
        for (int i = 0; i < 35; i++)
            if (a[i] != b[i]) cnt++;
        return cnt;
    }
};