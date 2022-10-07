#include <iostream>
#include <vector>
using namespace std;

struct Graph {
	struct Edge {
		int rev, from, to, cap;
		Edge(int r, int f, int t, int c) : rev(r), from(f), to(t), cap(c) {}
	};

	vector<vector<Edge>> list;

	Graph(int N = 0) : list(N) {}

	size_t size() {
		return list.size();
	}

	vector<Edge> &operator [] (int i) {
		return list[i];
	}

	Edge& redge(const Edge &e) {
		return list[e.to][e.rev];
	}

	void run_flow(Edge &e, int f) {
		e.cap -= f;
		redge(e).cap += f;
	}

	void addedge(int from, int to, int cap) {
		int fromrev = (int)list[from].size();
		int torev = (int)list[to].size();
		list[from].push_back(Edge(torev, from, to, cap));
		list[to].push_back(Edge(fromrev, to, from, 0));
	}
};

struct FordFulkerson {
	static const int INF = 1 << 30;
	vector<bool> seen;

	FordFulkerson() {}

	int fodfs(Graph &G, int v, int t, int f) {
		if (v == t) return f;

		seen[v] = true;

		for (auto &e : G[v]) {
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
			seen.assign((int)G.size(), 0);
			int flow = fodfs(G, s, t, INF);

			if (flow == 0) return res;

			res += flow;
		}

		return 0;
	}
};

int main() {
	int N, M, s, t;
	cin >> N >> M >> s >> t;
	--s, --t;
	
	const long long INF = 1LL << 60;
	vector<vector<long long>> dist(N, vector<long long>(N, INF));
	vector<vector<long long>> cap(N, vector<long long>(N, INF));
	for (int i = 0; i < M; ++i) {
		int u, v, d, c;
		cin >> u >> v >> d >> c; --u, --v;
		dist[u][v] = d;
		cap[u][v] = c;
	}

	vector<vector<long long>> dp(N, vector<long long>(N, INF));
	for (int u = 0; u < N; ++u) {
		for (int v = 0; v < M; ++v) dp[u][v] = dist[u][v];
		dp[u][u] = 0;
	}
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

	Graph G(N);
	for (int u = 0; u < N; ++u) {
			for (int v = 0; v < N; ++v) {
					if (u == v) continue;

					if (dp[s][u] + dist[u][v] + dp[v][t] == dp[s][t]) {
							G.addedge(u, v, cap[u][v]);
					}
			}
	}

	FordFulkerson ff;
	cout << ff.solve(G, s, t) << endl;
}