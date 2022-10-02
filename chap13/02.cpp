#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> bfs(const Graph &G, int s) {
	int N = (int)G.size();
	vector<int> dist(N, -1);
	queue<int> que;

	dist[s] = 0;
	que.push(s);
	
	while (!que.empty()) {
		int v = que.front();
		que.pop();

		for (auto c : G[v]) {
			if (dist[c] != -1) continue;

			dist[c] = dist[v] + 1;
			que.push(c);
		}
	}
	return dist;
}

int main() {
	int N, M;
	cin >> N >> M;

	Graph G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(a);
		G[b].push_back(b);
	}

	int s, t;
	cin >> s >> t;
	vector<int> dist = bfs(G, s);
	if (dist[t] != -1) cout << "Yes" << endl;
	else cout << "No" << endl;
}
