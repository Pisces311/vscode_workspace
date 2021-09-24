#include <bits/stdc++.h>
using namespace std;

template <class T>
class BIT {
    vector<T> c;
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) ans += c[i];
        return ans;
    }

   public:
    BIT(int n) : c(vector<T>(n + 1)) {}

    // 1-based
    BIT(vector<T>& a) : c(vector<T>(a.size() + 1)) {
        for (int i = 0; i < a.size(); i++) update(i + 1, a[i]);
    }

    T getSum(int l, int r) { return sum(r) - sum(l - 1); }

    void update(int x, T val) {
        for (int i = x; i < c.size(); i += i & -i) c[i] += val;
    }
};