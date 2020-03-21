#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mem(a, b) memset(a, b, sizeof(a))
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)
#define link(i, u) for (int i = head[u]; i != -1; i = edge[i].next)

const int maxn = 1e5 + 5;

struct word {
    string s;
    int num;
    char last;
    bool operator<(const word& a) const {
        return num == a.num ? last < a.last : num < a.num;
    }
} a[maxn];

int n;
string tmp;
bool vis[maxn];
char vowel[] = {'a', 'e', 'i', 'o', 'u'};
vector<pair<int, int> > high, low;

inline int check(string s) {
    int cnt = 0;
    up(i, 0, (int)s.size() - 1) up(j, 0, 4) if (s[i] == vowel[j])++ cnt;
    return cnt;
}

inline char get(string s) {
    dn(i, (int)s.size() - 1, 0) up(j, 0, 4) if (s[i] == vowel[j]) return s[i];
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);

    cin >> n;
    up(i, 1, n) {
        cin >> tmp;
        a[i] = {tmp, check(tmp), get(tmp)};
    }
    sort(a + 1, a + n + 1);
    up(i, 1, n - 1) if (!vis[i]) {
        if (a[i].num == a[i + 1].num && a[i].last == a[i + 1].last) {
            high.push_back({i, i + 1});
            vis[i] = true;
            vis[i + 1] = true;
        }
    }
    up(i, 1, n - 1) if (!vis[i]) {
        int next = i + 1;
        while (vis[next]) ++next;
        if (a[i].num == a[next].num) {
            low.push_back({i, next});
            vis[i] = true;
            vis[next] = true;
        }
    }
    int lsz = low.size(), hsz = high.size();
    if (lsz >= hsz) {
        cout << hsz << endl;
        up(i, 0, hsz - 1) {
            cout << a[low[i].first].s << ' ' << a[high[i].first].s << endl;
            cout << a[low[i].second].s << ' ' << a[high[i].second].s << endl;
        }
    } else {
        int spe = (hsz - lsz) / 2;
        cout << lsz + spe << endl;
        up(i, 0, lsz - 1) {
            cout << a[low[i].first].s << ' ' << a[high[i].first].s << endl;
            cout << a[low[i].second].s << ' ' << a[high[i].second].s << endl;
        }
        up(i, lsz, hsz - 2) {
            cout << a[high[i].first].s << ' ' << a[high[i + 1].first].s << endl;
            cout << a[high[i].second].s << ' ' << a[high[i + 1].second].s
                 << endl;
            ++i;
        }
    }

    return 0;
}