#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "utf8.h"
using namespace std;

struct block {
    int low, high;
    string type;
};

int htd(char ch) {
    if ('0' <= ch && ch <= '9') return ch - '0';
    if (ch == 'A') return 10;
    if (ch == 'B') return 11;
    if (ch == 'C') return 12;
    if (ch == 'D') return 13;
    if (ch == 'E')
        return 14;
    else
        return 15;
}

int parse(string s) {
    int num = htd(s.front());
    for (int i = 1; i < s.size(); ++i) {
        num *= 16;
        num += htd(s.at(i));
    }
    return num;
}

int main() {
    ifstream file("Blocks.txt");
    vector<block> v;
    string line;
    while (getline(file, line)) {
        if (line.empty() || line.front() == '#') continue;
        block b;
        int i = line.find_first_of('.'), j = line.find_first_of(';');
        b.low = parse(line.substr(0, i));
        b.high = parse(line.substr(i + 2, j - i - 2));
        b.type = line.substr(j + 2);
        v.push_back(b);
    }
    file.close();
    vector<int> cnt(v.size(), 0);
    while (cin >> line) {
        unsigned char *p;
        int bytes_in_char;
        int i;
        unsigned int codepoint;

        p = (unsigned char *)line.c_str();
        while (*p) {
            codepoint = utf8_to_codepoint(p, &bytes_in_char);
            if (codepoint) {
                for (int i = 0; i < v.size(); ++i) {
                    if (v[i].low <= codepoint && codepoint <= v[i].high)
                        ++cnt[i];
                }
                _utf8_incr(p);
            } else {
                cout << *p << " Invalid UTF-8" << endl;
                p++;
            }
        }
    }
    int Max = 0, ans = -1;
    for (int i = 0; i < cnt.size(); ++i) {
        if (cnt[i] > Max) {
            Max = cnt[i];
            ans = i;
        }
    }
    cout << v[ans].type << endl;
    return 0;
}