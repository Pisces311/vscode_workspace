#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

struct node {
    int prev, next;
} team[maxn];

int T, N, M;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> M;
        int last = 0;
        for (int i = 1, val; i <= N; ++i) {
            cin >> val;
            ++val;
            team[val] = {last, N + 1};
            if (last != -1) team[last].next = val;
            last = val;
        }
        team[N + 1].prev = last;
        while (M--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ++x1, ++x2, ++y1, ++y2;
            swap(team[team[x1].prev].next, team[team[x2].prev].next);
            swap(team[x1].prev, team[x2].prev);
            swap(team[team[y1].next].prev, team[team[y2].next].prev);
            swap(team[y1].next, team[y2].next);
        }
        int head;
        for (int i = 1; i <= N; ++i)
            if (team[i].prev == 0) head = i;
        for (int i = 0; i < N; ++i) {
            cout << head - 1 << ' ';
            head = team[head].next;
        }
        cout << '\n';
    }

    return 0;
}