#include <bits/stdc++.h>
using namespace std;

void solve() {
    using ll = long long;
    ll limit = 1000000000;

    int N;
    cin >> N;
    vector<ll> mine(N);
    mine[0] = 1;
    for (int i = 1; i < N; i++) {
        if (mine[i - 1] * 2 < limit) {
            mine[i] = mine[i - 1] * 2;
        } else {
            mine[i] = mine[i - 1] - 1;
        }
    }
    ll msum = accumulate(mine.begin(), mine.end(), 0ll);
    for (int i : mine) cout << i << ' ';
    cout << endl;
    // cout << "msum: " << msum << endl;
    vector<ll> judge(N);
    for (ll &i : judge) {
        cin >> i;
        // i = (rand() % 1000000) + 1;
    }
    // for (int i : judge) cout << i << ' ';
    // cout << endl;
    sort(judge.begin(), judge.end());
    ll jsum = accumulate(judge.begin(), judge.end(), 0ll);
    // cout << "jsum: " << jsum << endl;
    while (jsum > msum) {
        jsum -= judge.back();
        msum += judge.back();
        judge.pop_back();
    }
    // cout << "target: " << (msum + jsum) / 2 << endl;
    ll mask = (msum - jsum) / 2;
    while (mask > limit) {
        ll back = mine.back();
        msum -= back;
        jsum += back;
        mask = (msum - jsum) / 2;
        mine.pop_back();
        judge.push_back(back);
    }
    assert(0 <= mask && mask <= limit);
    // cout << "mask: " << mask << endl;
    for (int i = 0; (1 << i) <= limit; i++) {
        if (mask & (1 << i)) judge.push_back(1 << i);
    }
    for (int i : judge) cout << i << ' ';
    cout << endl;
    // ll cur = accumulate(judge.begin(), judge.end(), 0ll);
    // cout << "cur: " << cur << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}