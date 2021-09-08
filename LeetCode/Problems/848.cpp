#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for (int i = shifts.size() - 2; i >= 0; i--)
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        for (int i = 0; i < shifts.size(); i++)
            s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
        return s;
    }
};

int main() {
    Solution a;
    vector<int> v = {26, 9, 17};
    string s = "ruu";
    cout << a.shiftingLetters("ruu", v) << endl;
    return 0;
}