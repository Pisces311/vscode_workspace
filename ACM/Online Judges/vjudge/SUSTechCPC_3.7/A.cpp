#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 130;

char s[maxn];

bool is_upper(char c) { return (c >= 'A' && c <= 'Z'); }
bool is_lower(char c) { return (c >= 'a' && c <= 'z'); }
bool is_alphabet(char c) { return is_upper(c) || is_lower(c); }

bool check(int l, int r) {
    if (r - l + 1 == 1) return false;
    if (!is_upper(s[l])) return false;
    for (int i = l + 1; i <= r; ++i)
        if (!is_lower(s[i])) return false;
    return true;
}

void print(int l, int r) {
    for (int i = l; i <= r; ++i) putchar(s[i]);
}

void print2(int l, int r) {
    for (int i = l; i <= r; ++i)
        if (is_upper(s[i])) putchar(s[i]);
    printf(" (");
    for (int i = l; i <= r; ++i) putchar(s[i]);
    putchar(')');
}

int main() {
    freopen("abbreviation.in", "r", stdin);
    freopen("abbreviation.out", "w", stdout);

    while (gets(s)) {
        int n = strlen(s), bgn1, end = -1, cnt = 0, bgn2, end2 = -1;
        for (int i = 0; i < n; ++i) {
            if ((i == 0 || !is_alphabet(s[i - 1])) && is_alphabet(s[i])) {
                bgn1 = i;
            }
            if ((i == n - 1 || !is_alphabet(s[i + 1])) && is_alphabet(s[i])) {
                if (check(bgn1, i) &&
                    (cnt == 0 || (end == bgn1 - 2 && s[end + 1] == ' '))) {
                    ++cnt;
                    if (cnt == 1) {
                        bgn2 = bgn1;
                        end2 = end;
                    }
                } else if (check(bgn1, i)) {
                    if (cnt >= 2) {
                        print(end2 + 1, bgn2 - 1);
                        print2(bgn2, end);
                    } else if (cnt == 1) {
                        print(end2 + 1, bgn2 - 1);
                        print(bgn2, end);
                    }
                    cnt = 1;
                    bgn2 = bgn1;
                    end2 = end;
                } else {
                    if (cnt >= 2) {
                        print(end2 + 1, bgn2 - 1);
                        print2(bgn2, end);
                    } else if (cnt == 1) {
                        print(end2 + 1, bgn2 - 1);
                        print(bgn2, end);
                    }
                    print(end + 1, i);
                    cnt = 0;
                }
                end = i;
            }
        }
        if (cnt >= 2) {
            print(end2 + 1, bgn2 - 1);
            print2(bgn2, end);
        } else if (cnt == 1) {
            print(end2 + 1, bgn2 - 1);
            print(bgn2, end);
        }
        print(end + 1, n - 1);
        puts("");
    }

    return 0;
}