#include <string.h>
#include <iostream>
#include <string>
using namespace std;

char str1[50005], str2[50005];
int n[50005];
void get_next() {
    int len = strlen(str1), i, j;
    n[0] = j = -1;
    for (i = 0; i < len;) {
        if (j == -1 || str1[i] == str1[j])
            n[++i] = ++j;
        else
            j = n[j];
    }
}

int solve() {
    int len1 = strlen(str1), len2 = strlen(str2);
    int i, j = 0;
    for (i = 0; i < len2;) {
        if (j == -1 || str2[i] == str1[j]) {
            j++, i++;
            if (j == len1 && i != len2)
                j = n[j];
        } else
            j = n[j];
    }
    return j;
}

int main() {
    freopen("D:\in.txt", "r", stdin);
    int res;
    while (cin >> str1) {
        cin >> str2;
        if (str1[0] == '\0' && str2[0] == '\0') {
            printf("0\n");
            continue;
        }
        get_next();
        res = solve();
        str1[res] = '\0';
        if (res)
            printf("%s %d\n", str1, res);
        else
            cout << 0 << endl;
    }

    return 0;
}