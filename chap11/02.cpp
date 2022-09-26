#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> par, siz;

	UnionFind(int n) : par(n, -1), siz(n, 1) { }

	int root(int x) {
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool unite(int x, int y) {
		x = root(x), y = root(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) swap(x, y);
		par[y] = x;
		siz[x] += siz[y];
		return true;
	}

	int size(int x) {
		return siz[root(x)];
	}
};

int main() {
	int V, E;
	cin >> V >> E;
	vector<pair<int, int>> e(E);
	for (int i = 0; i < E; ++i) {
		cin >> e[i].first >> e[i].second;
		--e[i].first, --e[i].second;
	}

	UnionFind uf(V);
	int cur = V;
	vector<long long> res;
	for (int i = 0; i < E; ++i) {
		res.push_back(cur);

		int a = e[E - 1 - i].first, b = e[E - 1 - i].second;
		if (uf.issame(a, b)) continue;

		int sa = uf.size(a), sb = uf.size(b);
		cur -= sa * sb;
		uf.unite(a, b);
	}

	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;
}