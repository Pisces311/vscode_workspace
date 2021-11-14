#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.size() == 0) return "";
        int tot = encodedText.size();
        int cols = tot / rows;
        vector<vector<char>> m(rows, vector<char>(cols));
        int p = 0;
        for (int i = 0; i < rows; i++) {
            for (char& ch : m[i]) {
                ch = encodedText[p];
                p++;
            }
        }
        string ans = "";
        for (int y = 0; y < cols; y++) {
            for (int i = 0, j = y; i < rows && j < cols; i++, j++) {
                ans += m[i][j];
            }
        }
        p = ans.size() - 1;
        int zcnt = 0;
        while (ans[p] == ' ') {
            p--;
            zcnt++;
        }
        return ans.substr(0, ans.size() - zcnt);
    }
};