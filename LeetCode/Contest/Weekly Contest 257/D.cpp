#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent;

   public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) { return x == parent[x] ? x : parent[x] = find(parent[x]); }

    bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return false;  // Return False if u and v are already union
        parent[pv] = pu;
        return true;
    }
};

class Solution {
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

   public:
    bool gcdSort(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        sieve(maxNum + 1);

        UnionFind uf(maxNum + 1);
        for (int x : nums)
            for (int f : getPrimeFactors(x)) uf.Union(x, f);

        vector<int> sortedArr(nums);
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < nums.size(); ++i)
            if (uf.find(nums[i]) != uf.find(sortedArr[i]))
                return false;  // can't swap nums[i] with sortedArr[i]
        return true;
    }
};