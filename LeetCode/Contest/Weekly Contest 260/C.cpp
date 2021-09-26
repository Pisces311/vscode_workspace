#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board.front().size();
        int wordLen = word.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // left to right
                if ((j == 0 || board[i][j - 1] == '#') && j + wordLen <= m) {
                    bool flag = true;
                    for (int k = 0; k < wordLen; k++) {
                        if (board[i][j + k] != ' ' &&
                            board[i][j + k] != word[k])
                            flag = false;
                    }
                    if (flag &&
                        (j + wordLen == m || board[i][j + wordLen] == '#'))
                        return true;
                }
                // right to left
                if ((j == m - 1 || board[i][j + 1] == '#') &&
                    j - wordLen >= -1) {
                    bool flag = true;
                    for (int k = 0; k < wordLen; k++) {
                        if (board[i][j - k] != ' ' &&
                            board[i][j - k] != word[k])
                            flag = false;
                    }
                    if (flag &&
                        (j - wordLen == -1 || board[i][j - wordLen] == '#'))
                        return true;
                }
                // up to down
                if ((i == 0 || board[i - 1][j] == '#') && i + wordLen <= n) {
                    bool flag = true;
                    for (int k = 0; k < wordLen; k++) {
                        if (board[i + k][j] != ' ' &&
                            board[i + k][j] != word[k])
                            flag = false;
                    }
                    if (flag &&
                        (i + wordLen == n || board[i + wordLen][j] == '#'))
                        return true;
                }
                // down to up
                if ((i == n - 1 || board[i + 1][j] == '#') &&
                    i - wordLen >= -1) {
                    bool flag = true;
                    for (int k = 0; k < wordLen; k++) {
                        if (board[i - k][j] != ' ' &&
                            board[i - k][j] != word[k])
                            flag = false;
                    }
                    if (flag &&
                        (i - wordLen == -1 || board[i - wordLen][j] == '#'))
                        return true;
                }
            }
        }
        return false;
    }
};