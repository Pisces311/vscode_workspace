#include <bits/stdc++.h>
using namespace std;

class fraction {
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    int lcm(int a, int b) { return a / gcd(a, b) * b; }
    int sign(int x) { return (x > 0 ? 1 : -1); }
    void reduce() {
        int m = gcd(abs(a), abs(b));
        a /= m * sign(b);
        b = (a ? abs(b / m) : 1);
    }

   public:
    int a, b;
    fraction() : a(0), b(1) {}
    fraction(int x) : a(x), b(1) {}
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
            out << 0;
        else if (f.b == 1)
            out << f.a;
        else
            out << f.a << '/' << f.b;
        return out;
    }
};