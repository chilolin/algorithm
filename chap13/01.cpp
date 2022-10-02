#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v) {
	seen[v] = true;
	for (auto c : G[v]) {
		if (seen[c]) continue;
		dfs(G, c);
	}
}

int main() {
	int N;
	cin >> N;

	Graph G(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int res = 0;
	seen.assign(N, false);
	for (int v = 0; v < N; ++v) {
		if (seen[v]) continue;
		dfs(G, v);
		++res;
	}
	cout << res << endl;
}