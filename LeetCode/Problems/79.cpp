#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, m;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, string word, int x, int y, int ind) {
        if (ind == word.size()) return true;
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != word[ind])
            return false;
        char tmp = board[x][y];
        board[x][y] = '#';
        bool match = dfs(board, word, x + 1, y, ind + 1) ||
                     dfs(board, word, x - 1, y, ind + 1) ||
                     dfs(board, word, x, y + 1, ind + 1) ||
                     dfs(board, word, x, y - 1, ind + 1);
        board[x][y] = tmp;
        return match;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};