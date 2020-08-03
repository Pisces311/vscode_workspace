#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 3e2 + 5;

struct card {
    int pro[5];
} a[maxn];

int T, N;
string str;
vector<int> ans;

void match(int i, int j) {
    if (str.substr(j + 1, 3) == "one") a[i].pro[1] = 1;
    if (str.substr(j + 1, 3) == "two") a[i].pro[1] = 2;
    if (str.substr(j + 1, 3) == "thr") a[i].pro[1] = 3;
    if (str.substr(j + 1, 3) == "dia") a[i].pro[2] = 1;
    if (str.substr(j + 1, 3) == "squ") a[i].pro[2] = 2;
    if (str.substr(j + 1, 3) == "ova") a[i].pro[2] = 3;
    if (str.substr(j + 1, 3) == "sol") a[i].pro[3] = 1;
    if (str.substr(j + 1, 3) == "str") a[i].pro[3] = 2;
    if (str.substr(j + 1, 3) == "ope") a[i].pro[3] = 3;
    if (str.substr(j + 1, 3) == "red") a[i].pro[4] = 1;
    if (str.substr(j + 1, 3) == "gre") a[i].pro[4] = 2;
    if (str.substr(j + 1, 3) == "pur") a[i].pro[4] = 3;
}

bool check_property(int i, int j, int k, int l) {
    if (!a[i].pro[l] || !a[j].pro[l] || !a[k].pro[l]) return true;
    if (a[i].pro[l] == a[j].pro[l] && a[i].pro[l] == a[k].pro[l]) return true;
    if (a[i].pro[l] != a[j].pro[l] && a[i].pro[l] != a[k].pro[l] &&
        a[j].pro[l] != a[k].pro[l])
        return true;
    return false;
}

bool check(int i, int j, int k) {
    for (int l = 1; l <= 4; ++l) {
        if (!check_property(i, j, k, l)) return false;
    }
    return true;
}

bool solve() {
    for (int i = 1; i <= N; ++i) {
        ans.push_back(i);
        for (int j = i + 1; j <= N; ++j) {
            ans.push_back(j);
            for (int k = j + 1; k <= N; ++k) {
                ans.push_back(k);
                if (check(i, j, k)) return true;
                ans.pop_back();
            }
            ans.pop_back();
        }
        ans.pop_back();
    }
    return false;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    int cas = 0;
    while (T--) {
        cout << "Case #" << ++cas << ": ";
        cin >> N;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= N; ++i) {
            cin >> str;
            for (int j = 0; j < str.size(); ++j) {
                if (str[j] == '[') match(i, j);
            }
        }
        ans.clear();
        if (solve())
            cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}