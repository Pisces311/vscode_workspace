#include <bits/stdc++.h>
using namespace std;

// 0 based, 返回字符串循环同构最小表示法起始下标
int least_rotation(string s) {
    int n = s.size();
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) {
            ++k;
        } else {
            s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) ++i;
            k = 0;
        }
    }
    return min(i, j);
}