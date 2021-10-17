#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool winnerOfGame(string colors) {
        int A = 0, B = 0;
        for (int i = 1; i < colors.size() - 1; i++) {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1] &&
                colors[i] == 'A')
                A++;
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1] &&
                colors[i] == 'B')
                B++;
        }
        if (!A) return false;
        return A > B;
    }
};