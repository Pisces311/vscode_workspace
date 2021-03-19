#include <iostream>
using namespace std;

char vowels[] = {"aeiouAEIOU"};

bool check_vowel(char ch) {
    for (int i = 0; i < 10; i++) {
        if (vowels[i] == ch)
            return true;
    }
    return false;
}

int main() {
    int V = 0, C = 0, O = 0;
    cout << "Enter word (q to quit):" << endl;
    while (true) {
        string s;
        cin >> s;
        if (s == "q")
            break;
        else if (!isalpha(s[0]))
            O += 1;
        else if (check_vowel(s[0]))
            V += 1;
        else
            C += 1;
    }
    cout << V << " words beginning with vowels" << endl;
    cout << C << " words beginning with consonants" << endl;
    cout << O << " others" << endl;
    return 0;
}