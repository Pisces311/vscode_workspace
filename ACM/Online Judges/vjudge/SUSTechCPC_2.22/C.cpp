#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;

ifstream fin("consonant.in");
ofstream fout("consonant.out");

int n;
char s[maxn];
bitset<25> bit;
int num[25][25];
map<char, int> dic;
char vowels[] = {"aeiouwy"};

bool is_consonant(char a) {
    for (int i = 0; i < 7; ++i)
        if (vowels[i] == a) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    fin >> s;
    int n = strlen(s);
    int no = 0;
    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        if (is_consonant(c)) dic[c] = ++no;
    }
    for (int i = 1; i < n; ++i) {
        if (dic[s[i - 1]] && dic[s[i]]) ++num[dic[s[i - 1]]][dic[s[i]]];
    }
    int ans = 0, idx = -1;
    for (int i = 0; i < (1 << 19); ++i) {
        bit = i;
        int cnt = 0;
        for (int j = 1; j <= 19; ++j) {
            for (int k = 1; k <= 19; ++k) {
                if (k == j) continue;
                if (bit[k] + bit[j] == 1) cnt += num[j][k];
            }
        }
        if (ans < cnt) {
            ans = cnt;
            idx = i;
        }
    }
    bit = idx;
    for (int i = 0; i < n; ++i) {
        if (bit[dic[s[i]]]) s[i] -= 32;
    }
    fout << s << '\n';

    return 0;
}
