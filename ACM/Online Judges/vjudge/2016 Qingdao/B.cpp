#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

int N;
int ori[30];
int cur[30];

inline bool valid_check() {
    for (int i = 1; i <= 24; i += 4) {
        if (cur[i] == cur[i + 1] && cur[i + 1] == cur[i + 2] &&
            cur[i + 2] == cur[i + 3])
            continue;
        else
            return false;
    }
    return true;
}

inline bool left_forward() {
    for (int i = 5; i <= 15; i += 2) cur[i] = ori[i - 4];
    cur[1] = ori[13];
    cur[3] = ori[15];
    if (valid_check()) return true;
    return false;
}
inline bool left_back() {
    for (int i = 1; i <= 11; i += 2) cur[i] = ori[i + 4];
    cur[13] = ori[1];
    cur[15] = ori[3];
    if (valid_check()) return true;
    return false;
}

inline bool front_left() {
    int lst[] = {19, 20, 3, 4, 23, 24, 10, 9};
    cur[lst[6]] = ori[lst[0]];
    cur[lst[7]] = ori[lst[1]];
    for (int i = 0; i < 6; ++i) cur[lst[i]] = ori[lst[i + 2]];
    if (valid_check()) return true;
    return false;
}
inline bool front_right() {
    int lst[] = {19, 20, 3, 4, 23, 24, 10, 9};
    cur[lst[0]] = ori[lst[6]];
    cur[lst[1]] = ori[lst[7]];
    for (int i = 2; i < 8; ++i) cur[lst[i]] = ori[lst[i - 2]];
    if (valid_check()) return true;
    return false;
}

inline bool top_left() {
    int lst[] = {18, 20, 5, 6, 23, 21, 16, 15};
    cur[lst[6]] = ori[lst[0]];
    cur[lst[7]] = ori[lst[1]];
    for (int i = 0; i < 6; ++i) cur[lst[i]] = ori[lst[i + 2]];
    if (valid_check()) return true;
    return false;
}
inline bool top_right() {
    int lst[] = {18, 20, 5, 6, 23, 21, 16, 15};
    cur[lst[0]] = ori[lst[6]];
    cur[lst[1]] = ori[lst[7]];
    for (int i = 2; i < 8; ++i) cur[lst[i]] = ori[lst[i - 2]];
    if (valid_check()) return true;
    return false;
}

inline bool turn() {
    memcpy(cur, ori, sizeof(ori));
    if (valid_check()) return true;
    if (left_forward()) return true;
    memcpy(cur, ori, sizeof(ori));
    if (left_back()) return true;
    memcpy(cur, ori, sizeof(ori));
    if (front_left()) return true;
    memcpy(cur, ori, sizeof(ori));
    if (front_right()) return true;
    memcpy(cur, ori, sizeof(ori));
    if (top_left()) return true;
    memcpy(cur, ori, sizeof(ori));
    if (top_right()) return true;
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    while (N--) {
        for (int i = 1; i <= 24; ++i) cin >> ori[i];
        if (turn())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}