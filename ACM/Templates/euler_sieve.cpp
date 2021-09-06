#include <bits/stdc++.h>
using namespace std;

vector<int> spf;  // the smallest prime factor of number x (x >= 2)
vector<int> prime;

void sieve(int n) {  // O(Nlog(logN)) ~ O(N)
    spf.resize(n + 1);
    for (int i = 2; i <= n; ++i) spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {  // `i` is a prime number
            for (int j = i * i; j < n; j += i)
                if (spf[j] > i)
                    spf[j] = i;  // update to the smallest prime factor of j
        }
    }
    for (int i = 2; i <= n; i++)
        if (spf[i] == i) prime.push_back(i);
}

vector<int> getPrimeFactors(int n) {  // O(logN)
    vector<int> factors;
    while (n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}