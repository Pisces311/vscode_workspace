#include <bits/stdc++.h>
using namespace std;

class Encrypter {
    vector<string> valid;
    map<char, string> encry;

   public:
    Encrypter(vector<char>& keys, vector<string>& values,
              vector<string>& dictionary) {
        encry.clear();
        for (int i = 0; i < keys.size(); i++) {
            encry[keys[i]] = values[i];
        }
        valid = dictionary;
    }

    string encrypt(string word1) {
        string ans = "";
        for (char ch : word1) {
            ans += encry[ch];
        }
        return ans;
    }

    int decrypt(string word2) {
        int ans = 0;
        for (string& str : valid) {
            if (encrypt(str) == word2) ans++;
        }
        return ans;
    }
};