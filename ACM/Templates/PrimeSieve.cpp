#include <bits/stdc++.h>
using namespace std;

vector<int> spf;  // the smallest prime factor of number x (x >= 2)
vector<int> prime;

void Eratosthenes(int n) {  // O(NloglogN)
    spf.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {  // `i` is a prime number
            for (int j = i * i; j <= n; j += i)
                if (spf[j] > i)
                    spf[j] = i;  // update to the smallest prime factor of j
        }
    }
    for (int i = 2; i <= n; i++)
        if (spf[i] == i) prime.push_back(i);
}

vector<bool> isPrime;

void Euler(int n) {  // O(N)
    isPrime.assign(n + 1, true);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) prime.push_back(i);
        for (int p : prime) {
            if (p * i > n) break;
            isPrime[p * i] = false;
            if (i % p == 0) break;
        }
    }
}

vector<int> getPrimeFactors(int n) {  // O(logN)
    vector<int> factors;
    while (n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}