#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int len;
char str[200];
char msg[200];
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool valid() {
    int x = strlen(str);
    if (x != 8) return false;
    for (int i = 0; i < x; ++i)
        if (str[i] < '0' || str[i] > '9') return false;
    return true;
}

int parse(int l, int r) {
    int ret = 0;
    for (int i = l; i < r; i++) {
        ret *= 10;
        ret += str[i] - '0';
    }
    return ret;
}

bool more(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }

bool check(int y, int m, int d) {
    if (y < 1900 || y > 2020) return false;
    if (m < 1 || m > 12) return false;
    if (more(y) && m == 2) {
        if (d < 1 || d > 29) return false;
    } else if (d < 1 || d > month[m])
        return false;
    return true;
}

bool is_lower(char ch) { return 'a' <= ch && ch <= 'z'; }
bool is_upper(char ch) { return 'A' <= ch && ch <= 'Z'; }

bool check_msg() {
    for (int i = 0; i < len; ++i) {
        if (is_lower(msg[i]) || is_upper(msg[i]) || msg[i] == ' ') continue;
        return false;
    }
    return true;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    while (~scanf("%s", &str)) {
        getchar();
        scanf("%[^\n]", &msg);
        len = strlen(msg);
        if (!valid()) {
            puts("none");
            continue;
        }
        int y = parse(0, 4), m = parse(4, 6), d = parse(6, 8);
        if (!check(y, m, d)) {
            puts("none");
            continue;
        }
        int date = parse(0, 8);
        while (date >= 10) {
            int sum = 0;
            while (date > 0) sum += date % 10, date /= 10;
            date = sum;
        }
        if (!check_msg()) {
            puts("none");
            continue;
        }
        for (int i = 0; i < len; ++i) {
            if (msg[i] == ' ') {
                putchar('#');
            } else if (is_lower(msg[i])) {
                char c = (msg[i] - 'a' + date) % 26 + 'a';
                putchar(c);
            } else {
                char c = (msg[i] - 'A' + date) % 26 + 'A';
                putchar(c);
            }
        }
        puts("");
    }

    return 0;
}