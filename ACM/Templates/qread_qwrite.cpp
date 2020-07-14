#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

namespace IO {
namespace READONLY {
const int Rlen = 1 << 18 | 1;
char buf[Rlen], *p1, *p2;
char obuf[Rlen], *p3 = obuf;
char ch[23];
}  // namespace READONLY
inline char get_char() {
    using namespace READONLY;
    return (p1 == p2) &&
                   (p2 = (p1 = buf) + fread(buf, 1, Rlen, stdin), p1 == p2)
               ? EOF
               : *p1++;
}
inline void put_char(const char &c) {
    using namespace READONLY;
    *p3++ = c;
    if (p3 == obuf + Rlen) fwrite(obuf, 1, Rlen, stdout), p3 = obuf;
}
inline void put_s(const char *s) {
    for (; *s; ++s) putchar(*s);
    putchar('\n');
}
inline void FLUSH() {
    using namespace READONLY;
    fwrite(obuf, 1, p3 - obuf, stdout);
    p3 = obuf;
}

inline ll getint() {
    register ll num;
    register char c;
    while (!isdigit(c = getchar()))
        ;
    num = c ^ 48;
    while (isdigit(c = getchar())) num = (num + (num << 2) << 1) + (c ^ 48);
    return num;
}
inline void outint(ll a) {
    using namespace READONLY;
    if (a == 0) putchar('0');
    if (a < 0) putchar('-'), a = -a;
    while (a) ch[++ch[0]] = a - a / 10 * 10, a /= 10;
    while (ch[0]) putchar(ch[ch[0]--] ^ 48);
}
}  // namespace IO
using namespace IO;