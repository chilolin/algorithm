#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	} 
	return false;
}

using Graph = vector<vector<int>>;

int main() {
	int N, M, s, t;
	cin >> N >> M >> s >> t; --s, --t;

	Graph G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
	}

	vector<vector<long long>> dist(N, vector<long long>(3, -1));
	queue<pair<int, int>> que;
	dist[s][0] = 0;
	que.push(make_pair(s, 0));

	while (!que.empty()) {
		int v = que.front().first;
		int parity = que.front().second; 
		que.pop();

		int np = (parity + 1) % 3;
		for (auto nv : G[v]) {
			if (dist[nv][np] == -1) {
				dist[nv][np] = dist[v][parity] + 1;
				que.push(make_pair(nv, np));
			}
		}
	}

	if (dist[t][0] == -1) cout << -1 << endl;
	else cout << dist[t][0] << endl;
}