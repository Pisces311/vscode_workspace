#include <bits/stdc++.h>
using namespace std;

// iterates through all n-bit values that have k bits set to 1, from lowest to
// highest
vector<int> GospersHack(int n, int k) {
    vector<int> nums;
    int mask = (1 << k) - 1;
    int limit = (1 << n);
    while (mask < limit) {
        nums.push_back(mask);
        int c = mask & -mask;
        int r = mask + c;
        mask = (((r ^ mask) >> 2) / c) | r;
    }
    return nums;
}