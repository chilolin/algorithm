#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct UnionFind {
	vector<int> par, siz;

	UnionFind(int n) : par(n, -1), siz(n, -1) { }

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
};

using Edge = pair<int, pair<int, int>>;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<Edge> edges(M);
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w; --u, --v;
		edges[i] = Edge(w, make_pair(u, v));
	}

	sort(edges.begin(), edges.end());

	auto calc = [&](vector<int> &res, int id = -1) -> long long {
		long long cost = 0;
		res.clear();

		UnionFind uf(M);
		for (int e = 0; e < M; ++e) {
			if (e == id) continue;
			int w = edges[e].first;
			int u = edges[e].second.first;
			int v = edges[e].second.second;			
			if (uf.issame(u, v)) continue;
			res.push_back(e);
			uf.unite(u, v);
			cost += w;
		}

		if (res.size() < N - 1) return (1LL << 60);
		return cost;
	};

	vector<int> mst;
	long long base = calc(mst);

	vector<int> dammy;
	long long num = 0, res = 0;
	for (auto id : mst) {
		if (calc(dammy, id) > base) {
			++num;
			res += edges[id].first;
		}
	}
	cout << num << " " << res << endl;
}