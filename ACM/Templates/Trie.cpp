#include <bits/stdc++.h>
using namespace std;

class Trie {
    map<char, Trie*> next = {};
    bool isWord = false;

   public:
    Trie() {}

    void insert(string word) {
        Trie* u = this;
        for (char ch : word) {
            if (!u->next.count(ch)) u->next[ch] = new Trie();
            u = u->next[ch];
        }
        u->isWord = true;
    }

    bool search(string word) {
        Trie* u = this;
        for (char ch : word) {
            if (!u->next.count(ch)) return false;
            u = u->next[ch];
        }
        return u->isWord;
    }

    bool startsWith(string prefix) {
        Trie* u = this;
        for (char ch : prefix) {
            if (!u->next.count(ch)) return false;
            u = u->next[ch];
        }
        return true;
    }
};