#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

struct node {
    int l, r;
    bool operator<(const node& a) const { return l == a.l ? r < a.r : l < a.l; }
} a[maxn];

int N;

int merge(node A[], int begin, int mid, int end) {
    static int count = 0;
    node result[end - begin + 1];
    int i = begin;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (A[i].r <= A[j].r) {
            result[k++] = A[i++];
        } else {
            count += mid - i + 1;
            result[k++] = A[j++];
        }
    }
    while (j <= end) result[k++] = A[j++];
    while (i <= mid) result[k++] = A[i++];
    for (k = 0; k < end - begin + 1; k++) A[begin + k] = result[k];
    return count;
}

int mergeSort(node a[], int begin, int end) {
    int sum = 0;
    if (begin < end) {
        int mid = (begin + end) / 2;
        mergeSort(a, begin, mid);
        mergeSort(a, mid + 1, end);
        sum = merge(a, begin, mid, end);
    }
    return sum;
}

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i].l >> a[i].r;
    sort(a, a + N);
    int begin = 0, end = N - 1;
    cout << 1ll * N * (N - 1) / 2 - mergeSort(a, begin, end) << endl;

    return 0;
}