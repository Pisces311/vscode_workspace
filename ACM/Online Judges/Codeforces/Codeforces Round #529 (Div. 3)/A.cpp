#include <bits/stdc++.h>
using namespace std;

#define ite(i, a, b) for(int i = a; i <= b; ++i)

int n;
string a, b;

int main() {

	ios::sync_with_stdio(false);

	//freopen("D:\in.txt", "r", stdin);

	cin >> n >> a;
	for (int i = 0, j = 1; i <= n - 1; i += j, ++j) {
		b += a[i];
	}

	cout << b << endl;

	return 0;
}