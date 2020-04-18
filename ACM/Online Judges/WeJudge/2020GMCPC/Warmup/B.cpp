#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int maxn = 1e5 + 5;

int N, M;
vector<int> v;

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> M) {
        for (int i = 1; i <= N; ++i) {
            int G1;
            cin >> G1;
            v.clear();
            for (int i = 1; i <= N - 1; ++i) {
                int score;
                cin >> score;
                if (score > M || score < 0) continue;
                v.push_back(score);
            }
            sort(v.begin(), v.end());
            int sum = 0;
            for (int i = 1; i < v.size() - 1; ++i) sum += v[i];
            double avg = 1.0 * sum / (v.size() - 2);
            cout << (int)((avg + G1) / 2 + 0.5) << '\n';
        }
    }

    return 0;
}