#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long INF = 1LL << 60;

const vector<int> dx = {0, -1, 0, 1};
const vector<int> dy = {1, 0, -1, 0};

using Cell = pair<int, int>;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> field(H);
	for (int i = 0; i < H; ++i) cin >> field[i];

	int sx, sy, gx, gy = -1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (field[i][j] == 's') sx = j, sy = i;
			if (field[i][j] == 'g') gx = j, gy = i;
		}
	}

	vector<vector<int>> dist(H, vector<int>(W, INF));
	dist[sx][sy] = 0;

	deque<Cell> que;
	que.push_front(Cell(sx, sy));

	while (!que.empty()) {
		auto [x, y] = que.front();
		que.pop_front();

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];

			if ((0 > nx || nx > W - 1) || (0 > ny || ny > H - 1)) continue;
			
			if (field[nx][ny] != '#') {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					que.push_front(Cell(nx, ny));
				}
			}
			else {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					que.push_back(Cell(nx, ny));
				}
			}
		}

	}

	cout << dist[gx][gy] << endl;
}