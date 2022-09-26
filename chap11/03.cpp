#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct UnionFind {
	vector<int> par, siz;

	UnionFind(int num) : par(num, -1), siz(num, 1) { }

	bool issame(int a, int b) {
		return root(a) == root(b);
	}	

	int root(int a) {
		if (par[a] == -1) return a;
		else return par[a] = root(par[a]);
	}

	bool unite(int a, int b) {
		a = root(a), b = root(b);
		if (a == b) return false;
		if (siz[a] < siz[b]) swap(a, b);
		par[b] = a;
		siz[a] += siz[b];
		return true;
	}

	int size(int a) {
		return siz[a];
	}
};

int main() {
	int N, K, L;
	cin >> N >> K >> L;
	vector<pair<int, int>> k(K), l(L);
	for (int i = 0; i < K; ++i) cin >> k[i].first >> k[i].second;
	for (int i = 0; i < L; ++i) cin >> l[i].first >> l[i].second;

	UnionFind ufk(N), ufl(N);
	for (int i = 0; i < K; ++i) {
		ufk.unite(k[i].first, k[i].second);
	}
	for (int i = 0; i < L; ++i) {
		ufl.unite(l[i].first, l[i].second);
	}

	map<pair<int, int>, int> nums;
	for (int v = 0; v < N; ++v) {
		int root_road = ufk.root(v);
		int root_train = ufl.root(v);
		nums[make_pair(root_road, root_train)]++;
	}

	for (int i = 0; i < N; ++i) {
		int root_road = ufk.root(i);
		int root_train = ufl.root(i);
		cout << nums[make_pair(root_road, root_train)] << " ";
	}
	cout << endl;
}
	