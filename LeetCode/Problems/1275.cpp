#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> cb(3, vector<int>(3));
        for (int i = 0; i < moves.size(); i += 2)
            cb[moves[i][0]][moves[i][1]] = 1;
        for (int i = 1; i < moves.size(); i += 2)
            cb[moves[i][0]][moves[i][1]] = 2;
        for (int i = 0; i < 3; i++)
            if (cb[i][0] && cb[i][0] == cb[i][1] && cb[i][1] == cb[i][2])
                return cb[i][0] == 1 ? "A" : "B";
        for (int j = 0; j < 3; j++)
            if (cb[0][j] && cb[0][j] == cb[1][j] && cb[1][j] == cb[2][j])
                return cb[0][j] == 1 ? "A" : "B";
        if (cb[0][0] && cb[0][0] == cb[1][1] && cb[1][1] == cb[2][2])
            return cb[0][0] == 1 ? "A" : "B";
        if (cb[0][2] && cb[0][2] == cb[1][1] && cb[1][1] == cb[2][0])
            return cb[0][2] == 1 ? "A" : "B";
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};