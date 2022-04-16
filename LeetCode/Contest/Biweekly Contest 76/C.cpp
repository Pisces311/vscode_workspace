#include <bits/stdc++.h>
using namespace std;

class ATM {
    vector<long long> a = {20, 50, 100, 200, 500};
    vector<long long> cash;

   public:
    ATM() { cash = {0, 0, 0, 0, 0}; }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            cash[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> take(5);
        for (int i = 4; i >= 0; i--) {
            take[i] = min(amount / a[i], cash[i]);
            amount -= take[i] * a[i];
        }
        if (amount)
            return {-1};
        else {
            for (int i = 0; i < 5; i++) cash[i] -= take[i];
            return take;
        }
    }
};