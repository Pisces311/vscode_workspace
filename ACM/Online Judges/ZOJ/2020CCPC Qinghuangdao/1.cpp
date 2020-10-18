#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

struct fraction {
    int a, b;
    int sign(int x) { return (x > 0 ? 1 : -1); }
    fraction() : a(0), b(1) {}
    fraction(int x) : a(x), b(1) {}
    void reduce() {
        int m = gcd(abs(a), abs(b));
        a /= m * sign(b);
        b = (a ? abs(b / m) : 1);
    }
    fraction(int x, int y) : a(x), b(y) { reduce(); }
    bool operator<(const fraction &f) {
        int c = sign(b) * sign(f.b);
        return c < 0 ? a * f.b > f.a * b : a * f.b < f.a * b;
    }
    fraction operator+(const fraction &f) {
        int m = gcd(b, f.b);
        return fraction(f.b / m * a + b / m * f.a, b / m * f.b);
    }
    fraction operator+(const int &i) { return fraction(a + i * b, b); }
    fraction operator-(const fraction &f) {
        int m = gcd(b, f.b);
        return fraction(f.b / m * a - b / m * f.a, b / m * f.b);
    }
    fraction operator*(const fraction &f) {
        int m1 = gcd(abs(a), f.b);
        int m2 = gcd(b, abs(f.a));
        return fraction((a / m1) * (f.a / m2), (b / m2) * (f.b / m1));
    }
    fraction operator/(const fraction &f) {
        return (*this) * fraction(f.b, f.a);
    }
    friend ostream &operator<<(ostream &out, const fraction &f) {
        if (f.a == 0)
            cout << 0;
        else if (f.b == 1)
            cout << f.a;
        else
            cout << f.a << '/' << f.b;
        return out;
    }
};

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int a, b;
        cin >> a >> b;
        fraction ans(a * (a - 1), (a + b) * (a + b - 1));
        cout << "Case #" << i << ": ";
        if (!ans.a)
            cout << ans << "/1\n";
        else
            cout << ans << '\n';
    }

    return 0;
}