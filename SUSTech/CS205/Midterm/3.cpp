#include <algorithm>
#include <iostream>
using namespace std;

int dp[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int w[] = {0, 2, 3, 1, 5, 4, 3};
    int c[] = {0, 2, 2, 3, 1, 5, 2};
    for (int i = 1; i <= 6; ++i) {
        for (int v = n; v >= c[i]; --v) {
            dp[v] = max(dp[v], dp[v - c[i]] + w[i]);
        }
    }
    cout << *max_element(dp, dp + n + 1) << '\n';

    return 0;
}