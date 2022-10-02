#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	} 
	return false;
}

struct Edge {
	int to;
	long long w;
	Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
	int N, M;
	cin >> N >> M;

	Graph G(N);
	for (int i = 0; i < M; ++i) {
		int a, b; long long w;
		cin >> a >> b >> w; --a, --b;
		G[a].push_back(Edge(b, -w));
	}

	vector<long long> dist(N, INF);
	dist[0] = 0;
	for (int iter = 0; iter <= N*2; ++iter) {
		for (int v = 0; v < N; ++v) {
			if (dist[v] >= INF/2) continue;
			for (auto e : G[v]) {
				if (chmin(dist[e.to], dist[v] + e.w)) {
					if (iter >= N - 1) dist[e.to] = -INF;
				}
			}
		}
	}

	if (dist[N - 1] == -INF) cout << "inf" << endl;
	else cout << -dist[N - 1] << endl;
}