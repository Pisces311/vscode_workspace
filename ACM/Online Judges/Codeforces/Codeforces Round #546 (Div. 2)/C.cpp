#include <bits/stdc++.h>
using namespace std;

vector<int> A[1010];
vector<int> B[1010];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            int t;
            scanf("%d", &t);
            A[i + j].push_back(t);
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            int t;
            scanf("%d", &t);
            B[i + j].push_back(t);
        }
    for (int i = 0; i <= N + M - 2; ++i) {
        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end());
        if (A[i] != B[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}