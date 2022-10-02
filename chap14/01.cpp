#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int to;
	int w;
	Edge(int to, int w) : to(to), w(w) {};
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	} 
	return false;
}


Graph G;
vector<int> dp;
int rec(int v) {
	if (dp[v] != -1) return dp[v]; 

	int res = 0;
	for (auto next_v : G[v]) {
		chmax(res, rec(next_v.to) + next_v.w);
	}
	return dp[v] = res;
}

int main() {
	int N, M;
	cin >> N >> M;

	Graph G(N);
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		G[a].push_back(Edge(b, w));
	}

	int res = 0;
	for (int v = 0; v < N; ++v) chmax(res, rec(v));
	cout << res << endl;
}