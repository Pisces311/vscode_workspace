#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e3 + 1;

int n;
int SA_pref[maxn][maxn], stu_pref[maxn][maxn], inv[maxn][maxn];
int stu_status[maxn], SA_status[maxn], cnt[maxn];
queue<int> SA_free;

void creat_map(map<string, int>& m, string a[]) {
    int index = 0;
    string s;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        m[s] = ++index;
        a[index] = s;
    }
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    string SA_list[maxn], stu_list[maxn];
    map<string, int> SA_map;
    creat_map(SA_map, SA_list);
    map<string, int> stu_map;
    creat_map(stu_map, stu_list);
    string s;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> s;
            auto ite = stu_map.find(s);
            SA_pref[i][j] = ite->second;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> s;
            auto ite = SA_map.find(s);
            stu_pref[i][j] = ite->second;
            inv[i][ite->second] = j;
        }
    for (int i = 1; i <= n; ++i) SA_free.push(i);

    while (!SA_free.empty()) {
        int front = SA_free.front();
        SA_free.pop();
        while (!SA_status[front]) {
            int target = SA_pref[front][cnt[front] + 1];
            if (!stu_status[target]) {
                SA_status[front] = target;
                stu_status[target] = front;
            } else if (inv[target][stu_status[target]] > inv[target][front]) {
                SA_free.push(stu_status[target]);
                SA_status[stu_status[target]] = 0;
                SA_status[front] = target;
                stu_status[target] = front;
            }
            ++cnt[front];
        }
    }

    for (int i = 1; i <= n; ++i) cout << stu_list[SA_status[i]] << ' ';
    cout << endl;

    return 0;
}