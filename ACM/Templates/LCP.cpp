#include <bits/stdc++.h>
using namespace std;

void getLCP(string s) {
    const int n = s.size();

    // longest common prefix of s[i..] and s[j..]
    int lcp[n + 1][n + 1];
    for (int i = 0;i <= n;++i)
        lcp[i][n] = lcp[n][i] = 0;
    for (int i = n - 1;0 <= i;--i)
        for (int j = n - 1;0 <= j;--j)
            lcp[i][j] = s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0;
}