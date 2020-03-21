#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 1, maxm = 2e5 + 1;

#define ite(i, a, b) for(int i = a;i <= b;++i)

struct EDGE {
	int u, v;
	ll w;
	EDGE() {}
	EDGE(int u, int v, ll w) :u(u), v(v), w(w) {}
}edge[maxn + maxm];

int n, m, pos, u, v, top, counter;
int parent[maxn];
ll min_cost, sum, w;
ll cost[maxn];

inline void init() {
	counter = 0;
	sum = 0;
	top = 0;
	min_cost = 1e12 + 1;
	memset(parent, -1, sizeof(parent));
}

bool cmp(const EDGE& edge1, const EDGE& edge2) {
	return edge1.w < edge2.w;
}

inline int find(int x) {
	int pos;
	for (pos = x;parent[pos] > 0;pos = parent[pos]);
	while (pos != x) {
		int tmp = parent[x];
		parent[x] = pos;
		x = tmp;
	}
	return pos;
}

inline void Union(int u, int v) {
	int tmp = parent[u] + parent[v];
	if (parent[u] > parent[v]) {
		parent[u] = v;
		parent[v] = tmp;
	}
	else {
		parent[v] = u;
		parent[u] = tmp;
	}
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("D:\in.txt", "r", stdin);
	init();
	cin >> n >> m;
	ite(i, 1, n) {
		cin >> cost[i];
		if (min_cost > cost[i]) {
			min_cost = cost[i];
			pos = i;
		}
	}
	ite(i, 1, n)if(i != pos)
		edge[++top] = { pos,i, cost[i] + cost[pos] };
	ite(i, 1, m) {
		cin >> u >> v >> w;
		edge[++top] = { u, v, w };
	}
	sort(edge + 1, edge + m + n, cmp);
	ite(i, 1, m + n - 1) {
		int a = find(edge[i].u), b = find(edge[i].v);
		if (a != b) {
			sum += edge[i].w;
			Union(a, b);
			++counter;
			if (counter == n - 1)
				break;
		}
	}
	cout << sum << endl;

	return 0;
}