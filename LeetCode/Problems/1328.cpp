#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1) return "";
        for (int l = 0; l < palindrome.size(); l++) {
            if (palindrome[l] != 'a' && !(palindrome.size() & 1 && l == palindrome.size() / 2)) {
                palindrome[l] = 'a';
                return palindrome;
            }
        }
        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};