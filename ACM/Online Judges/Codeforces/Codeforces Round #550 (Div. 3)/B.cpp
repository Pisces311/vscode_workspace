#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

const int maxn = 2e3 + 5;

int n, num, sum = 0;
priority_queue<int, vector<int>, greater<int>> odd, even;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif

    scan(n);
    up(i, 1, n) {
        scan(num);
        if (num & 1)
            odd.push(num);
        else
            even.push(num);
    }
    int dif = (int)odd.size() - (int)even.size();
    if (dif == 0) {
        print(0);
        return 0;
    } else if (dif > 0) {
        --dif;
        while (dif--) {
            sum += odd.top();
            odd.pop();
        }
    } else {
        dif = -dif;
        --dif;
        while (dif--) {
            sum += even.top();
            even.pop();
        }
    }
    print(sum);

    return 0;
}