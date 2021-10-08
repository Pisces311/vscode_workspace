#include <bits/stdc++.h>
using namespace std;

class Solution {
    int reverseAns(string answerKey, int k) {
        int n = answerKey.size();
        for (int i = 0; i < n; i++)
            answerKey[i] = (answerKey[i] == 'T' ? 'F' : 'T');
        int r = n - 1, used = 0;
        for (int i = 0; i < n; i++) {
            if (answerKey[i] == 'T')
                continue;
            else if (used < k) {
                used++;
            } else {
                r = i - 1;
                break;
            }
        }
        int ans = r + 1;
        for (int l = 1; l < n; l++) {
            if (answerKey[l - 1] == 'F') used--;
            while (r + 1 < n && (answerKey[r + 1] == 'T' ||
                                 (answerKey[r + 1] == 'F' && used < k))) {
                r++;
                if (answerKey[r] == 'F') used++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int r = n - 1, used = 0;
        for (int i = 0; i < n; i++) {
            if (answerKey[i] == 'T')
                continue;
            else if (used < k) {
                used++;
            } else {
                r = i - 1;
                break;
            }
        }
        int ans = r + 1;
        for (int l = 1; l < n; l++) {
            if (answerKey[l - 1] == 'F') used--;
            while (r + 1 < n && (answerKey[r + 1] == 'T' ||
                                 (answerKey[r + 1] == 'F' && used < k))) {
                r++;
                if (answerKey[r] == 'F') used++;
            }
            ans = max(ans, r - l + 1);
        }
        return max(ans, reverseAns(answerKey, k));
    }
};