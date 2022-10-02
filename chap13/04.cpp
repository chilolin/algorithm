#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const vector<int> dx = {0, -1, 0, 1};
const vector<int> dy = {1, 0, -1, 0};

int main() {
	int H;
	vector<string> w(H);
	pair<int, int> S;
	pair<int, int> G;
	cin >> H;
	for (int i = 0; i < H; ++i) cin >> w[i];
	int W = w[0].size();
	cin >> S.first >> S.second;
	cin >> G.first >> G.second;
	
	vector<vector<int>> dist(H, vector<int>(W, -1));
	queue<pair<int, int>> que;

	dist[S.first][S.second] = 0;
	que.push(S);

	int cur = 0;
	while(!que.empty()) {
		pair<int, int> cell = que.front();
		const int x = cell.first;
		const int y = cell.second;
		que.pop();

		for (int i = 0; i < 4; ++i) {
			int next_x = x - dx[i];
			int next_y = y - dy[i];

			if (next_x < 0 || W - 1 < next_x) continue;
			if (next_y < 0 || H - 1 < next_y) continue;

			if (w[y].at(x) == '#') continue;

			if (dist[next_x][next_y] != -1) continue;

			dist[next_x][next_y] = dist[x][y] + 1;
			que.push({next_x, next_y});
		}
	}

	cout << dist[G.first][G.second] << endl;
}