#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(long long c) {
        for (long long i = 0; i * i <= c; i++) {
            long long ret = c - i * i;
            long long a = sqrt(ret);
            if (a * a == ret) return true;
        }
        return false;
    }
};