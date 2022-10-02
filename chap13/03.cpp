#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> color;
bool BFS(Graph &G, int s) {
	queue<int> que;

	color[s] = 0;
	que.push(s);

	int cur = 0;
	while(!que.empty()) {
		int v = que.front();
		que.pop();

		for (auto c : G[v]) {
			if (color[c] != -1) {
				if (color[c] == cur) return false;
				continue;
			}
			
			color[c] = 1 - color[v];
			que.push(c);
		}
	}
	return true;
}

int main() {
	int N, M;
	cin >> N >> M;

	Graph G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	color.assign(N, -1);
	bool res = true;
	for (int v = 0; v < N; ++v) {
		if (color[v] != -1) continue;
		if (!BFS(G, v)) res = false;
	}

	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
}