#include <bits/stdc++.h>
using namespace std;

#define DEBUG
typedef long long ll;
typedef pair<int, int> pii;
#define scan(a) scanf("%d", &a)
#define print(a) printf("%d\n", a)
#define up(i, a, b) for (int i = a; i <= b; ++i)
#define dn(i, a, b) for (int i = a; i >= b; --i)

string s;
int cnt_0 = 0, cnt_1 = 0;
int ans = 0;
bool zero = false;

int main() {
#ifdef DEBUG
    freopen("E:/source/Visual Studio Code/in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);

    cin >> s;
    s += "00";
    int sz = s.size();
    up(i, 0, sz - 1){
        if (s[i] == '1') {
            ++cnt_1;
            zero = false;
        }
        else if(zero)
            continue;
        else if(s[i + 1] != '0')
            ++cnt_0;
        else{
            ans += min(cnt_1, cnt_0 + 2);
            cnt_1 = cnt_0 = 0;
            zero = true;
            ++i;
        }
    }
    cout << ans << endl;

    return 0;
}