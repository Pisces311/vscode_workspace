#include <bits/stdc++.h>
using namespace std;

class Complex {
   private:
    double re, im;

   public:
    Complex() : re(0), im(0) {}
    Complex(double re, double im) : re(re), im(im) {}
    friend ostream &operator<<(ostream &os, Complex other) {
        if (other.im > 0)
            return os << other.re << " + " << other.im << 'i';
        else if (other.im < 0)
            return os << other.re << " - " << -other.im << 'i';
        else
            return os << other.re;
    }
    friend istream &operator>>(istream &is, Complex &other) {
        cout << "real:";
        is >> other.re;
        cout << "imaginary:";
        is >> other.im;
        return is;
    }
    Complex operator~() { return Complex(re, -im); }
    friend Complex operator+(Complex &a, Complex &b) {
        return Complex(a.re + b.re, a.im + b.im);
    }
    friend Complex operator-(Complex &a, Complex &b) {
        return Complex(a.re - b.re, a.im - b.im);
    }
    friend Complex operator*(Complex &a, Complex &b) {
        return Complex(a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re);
    }
    friend Complex operator*(int a, Complex &b) {
        return Complex(a * b.re, a * b.im);
    }
    Complex operator-(double re) { return Complex(this->re - re, this->im); }
    Complex operator=(Complex &a) { return Complex(a.re, a.im); }
    string operator==(Complex &a) {
        return (re == a.re && im == a.im) ? "true" : "false";
    }
    string operator!=(Complex &a) {
        return (re == a.re && im == a.im) ? "false" : "true";
    }
};

int main() {
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);

    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a + b is " << a + b << endl;
    cout << "a - b is " << a - b << endl;
    cout << "a - 2 is " << a - 2 << endl;
    cout << "a * b is " << a * b << endl;
    cout << "2 * a is " << 2 * a << endl;

    Complex c = b;
    cout << "b == c is " << (b == c) << endl;
    cout << "b != c is " << (b != c) << endl;
    cout << "a == c is " << (a == c) << endl << endl;

    Complex d;
    cout << "Enter a complex number: " << endl;
    cin >> d;
    cout << "d is " << d << endl;

    return 0;
}