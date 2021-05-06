#include "stock.h"

#include <bits/stdc++.h>
using namespace std;

Stock::Stock(const char *co, long n, double pr) {
    if (co) {
        company = new char[strlen(co) + 1];
        strcpy(company, co);
    } else {
        company = new char[1];
        *company = '\0';
    }
    if (n < 0) {
        cout << "Number of shares can't be negative; " << company
             << " shares set to 0." << endl;
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock() { delete company; }

void Stock::buy(long num, double price) {
    if (num < 0) {
        cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted." << endl;
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0) {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted." << endl;
    } else if (num > shares) {
        cout << "You can't sell more than you have!' "
             << "Transaction is aborted." << endl;
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

ostream &operator<<(ostream &os, const Stock &s) {
    os << "Company: " << s.company << " Shares: " << s.shares << endl;
    os << "\tShare Price: $" << s.share_val;
    cout << "\tTotal Worth: $" << s.total_val << endl;
    return os;
}

const Stock &Stock::topval(const Stock &s) const {
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
