#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::string;

inline long long read() {
    long long x = 0, f = 1;
    char c = getchar();
    for (; c > '9' || c < '0'; c = getchar()) {
        if (c == '-') f = -1;
    }
    for (; c >= '0' && c <= '9'; c = getchar()) {
        x = x * 10 + c - '0';
    }
    return x * f;
}

struct bign {
    int d[605], len;
    bool simbol;
    void clean() {
        while (len > 1 && !d[len - 1]) len--;
    }
    bign() {
        memset(d, 0, sizeof(d));
        len = 1;
        simbol=0;
    }
    bign(int num) { *this = num; }
    bign(char* num) { *this = num; }
    bign operator=(const char* num) {
        memset(d, 0, sizeof(d));
        len = strlen(num);
        for (int i = 0; i < len; i++){
            if(i==0&&num[i]=='')
            d[i] = num[len - 1 - i] - '0';
        }
        clean();
        return *this;
    }
    bign operator=(long long num) {
        char s[20];
        sprintf(s, "%lld", num);
        *this = s;
        return *this;
    }
    bign operator+(const bign& b) {
        bign c = *this;
        int i;
        for (i = 0; i < b.len; i++) {
            c.d[i] += b.d[i];
            if (c.d[i] > 9) c.d[i + 1]++, c.d[i] -= 10;
        }
        while (c.d[i] > 9) c.d[i++] -= 10, c.d[i]++;
        c.len = std::max(len, b.len);
        if (c.d[i] && c.len <= i) c.len = i + 1;
        return c;
    }
    bign operator-(const bign& b) {
        bign c = *this;
        int i;
        for (int i = 0; i < b.len; i++) {
            c.d[i] -= b.d[i];
            if (c.d[i] < 0) c.d[i] += 10, c.d[i + 1]--;
        }
        while (c.d[i] < 0) c.d[i++] += 10, c.d[i]--;
        c.clean();
        return c;
    }
    bign operator*(const bign& b) const {
        int i, j;
        bign c;
        c.len = len + b.len;
        for (j = 0; j < b.len; j++) {
            for (i = 0; i < len; i++) {
                c.d[i + j] += d[i] * b.d[j];
            }
        }
        for (i = 0; i < c.len; i++) c.d[i + 1] += c.d[i] / 10, c.d[i] %= 10;
        c.clean();
        return c;
    }
    bign operator/(const bign& b) {
        int i, j;
        bign c = *this, a = 0;
        for (i = len - 1; i >= 0; i--) {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++) {
                if (a < b * (j + 1)) break;
            }
            c.d[i] = j;
            a = a - b * j;
        }
        c.clean();
        return c;
    }
    bign operator%(const bign& b) {
        int i, j;
        bign a = 0;
        for (i = len - 1; i >= 0; i--) {
            a = a * 10 + d[i];
            for (j = 0; j < 10; j++) {
                if (a < b * (j + 1)) break;
            }
            a = a - b * j;
        }
        return a;
    }
    bign operator+=(const bign& b) {
        *this = *this + b;
        return *this;
    }
    bool operator<(const bign& b) const {
        if (len != b.len) return len < b.len;
        for (int i = len - 1; i >= 0; i--) {
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        }
        return false;
    }
    bool operator>(const bign& b) const { return b < *this; }
    bool operator==(const bign& b) const {
        return !(b < *this) && !(b > *this);
    }
    bool operator<=(const bign& b) const { return !(b < *this); }
    bool operator>=(const bign& b) const { return !(*this < b); }
    bool operator!=(const bign& b) const { return !(b == *this); }
    string str() const {
        char s[605] = {};
        for (int i = 0; i < len; i++) s[len - 1 - i] = d[i] + '0';
        return s;
    }
}m[505],a[505];
std::istream& operator>>(std::istream& in, bign& x) {
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
std::ostream& operator<<(std::ostream& out, const bign& x) {
    out << x.str();
    return out;
}

bign extend_gcd(bign a,bign b,bign &x,bign &y){
    if(a==0&&b==0)return -1;
    if(b==0){x=1;y=0ll;return a;}
    bign d=extend_gcd(b,a%b,y,x);
    y=y-a/b*x;
    return d;
}

bign abs(bign a,bign b){
    if(a>=b)return a-b;
    return b-a;
}

bool solve(bign &m0,bign &a0,bign m,bign a){
    bign y,x;
    bign g=extend_gcd(m0,m,x,y);
    if(abs(a,a0)%g!=0)return false;
    x=x*(a-a0)/g;
    x=x%(m/g);
    a=(x*m0+a0);
    m0=m0*(m/g);
    a0=a0%m0;
    if(a0<0)a0=a0+m0;
    return true;
}



inline void work() {

}

int main() {
    work();
    return 0;
}