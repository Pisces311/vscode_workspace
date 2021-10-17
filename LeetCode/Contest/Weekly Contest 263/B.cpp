#include <bits/stdc++.h>
using namespace std;

class Bank {
    int n;
    vector<long long> balance;

    bool check(int x) { return 1 <= x && x <= balance.size(); }

   public:
    Bank(vector<long long>& balance) : balance(balance) {}

    bool transfer(int account1, int account2, long long money) {
        if (!check(account1) || !check(account2)) return false;
        account1--, account2--;
        if (balance[account1] < money) return false;
        balance[account1] -= money;
        balance[account2] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!check(account)) return false;
        account--;
        balance[account] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!check(account)) return false;
        account--;
        if (balance[account] < money) return false;
        balance[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */