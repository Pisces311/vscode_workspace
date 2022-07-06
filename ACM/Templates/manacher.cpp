#include <bits/stdc++.h>
using namespace std;

class Manacher {
   public:
    string s;
    string enh;

    // longest palindrome radius centered at i (inclusive).
    // p[i]-1 is the length of the original palindromic string
    vector<int> p;
    Manacher(string s) : s(s), p(vector<int>((s.size() + 5) << 1)) {
        enh = "$#";
        for (int i = 0; i < s.size(); i++) {
            enh += s[i];
            enh += '#';
        }
        int id, mx = 0;
        for (int i = 1; i < enh.size(); i++) {
            p[i] = (i < mx ? min(p[2 * id - i], mx - i) : 1);
            while (enh[i - p[i]] == enh[i + p[i]]) p[i]++;
            if (mx < i + p[i]) {
                id = i;
                mx = i + p[i];
            }
        }
    }

    int palindromeLength() { return *max_element(p.begin() + 1, p.end()) - 1; }

    string palindrome() {
        int maxLen = palindromeLength();
        int pos = find(p.begin(), p.end(), maxLen + 1) - p.begin();
        string ret = "";
        for (int i = pos - maxLen; i <= pos + maxLen; i++)
            if (enh[i] != '#') ret += enh[i];
        return ret;
    }
};