#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct Graph {
	struct Edge {
		int from, to, rev, cap;
		Edge(int f, int t, int r, int c) : from(f), to(t), rev(r), cap(c) {}
	};

	Graph(int s) : list(s) {};

	vector<vector<Edge>> list;

	size_t size() {
		return list.size();
	}

	vector<Edge> &operator [] (int i) {
		return list[i];
	}

	Edge& redge(Edge e) {
		return list[e.to][e.rev];
	}

	void run_flow(Edge e, int f) {
		e.cap	-= f;
		redge(e).cap += f;
	}

	void addedge(int u, int v, int f) {
		size_t size_u = (int)list[u].size();
		size_t size_v = (int)list[v].size();
		list[u].push_back(Edge(u, v, size_v, f));
		list[v].push_back(Edge(v, u, size_u, 0));
	}
};

struct FordFullkerson {
	const long long INF = 1LL << 30;
	vector<bool> seen;

	FordFullkerson() {}

	int fodfs(Graph &G, int v, int t, int f) {
		if (v == t) return f;

		seen[v] = true;
		
		for (auto e: G[v]) {
			if (seen[e.to]) continue;

			if (e.cap == 0) continue;

			int flow = fodfs(G, e.to, t, min(f, e.cap));

			if (flow == 0) continue;

			G.run_flow(e, flow);

			return flow;
		}

		return 0;
	}

	int solve(Graph &G, int s, int t) {
		int res = 0;

		while (true) {
			seen.assign((int)G.size(), false);
			int flow = fodfs(G, s, t, INF);

			if (flow = 0) return res;

			res += flow;
		}

		return 0;
	}
};

int solve(int N, int M) {
	vector<int> b(N), c(M);
	for (int i = 0; i < N; ++i) cin >> b[i];
	for (int i = 0; i < M; ++i) cin >> c[i];

	Graph G(N + M + 2);
	int s = N + M, t = N + M + 1;

	for (int i = 0; i < N; ++i) {
		G.addedge(s, i, 1);
	}

	for (int i = 0; i < M; ++i) {
		G.addedge(i + N, t, 1);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (gcd(b[i], c[j]) > 1) {
				G.addedge(i, j+N, 1);
			}
		}
	}

	FordFullkerson ff;
	return ff.solve(G, s, t);
}

int main() {
	int M, N;
	while (cin >> M >> N) {
			if (M == 0) break;
			cout << solve(M, N) << endl;
	}
}