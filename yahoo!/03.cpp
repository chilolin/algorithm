#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> plate(H);
	for (int i = 0; i < H; ++i) cin >> plate[i];
	string ans;
	cin >> ans;

	vector<pair<int, int>> first(H*W, {-1, -1}), second(H*W, {-1, -1});
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (plate[i][j] == ans[0]) {
				first.push_back(make_pair(i, j));
				cout << i << j << endl;
			}
		}
	}

	for (auto p: first) {
		int h = p.first, w = p.second;

		if (h == -1 && w == -1) continue;

		for (int i = w; i < W; ++i) {
			if (plate[h][i] == ans[1]) {
				second.push_back(make_pair(h, i));
				cout << h << i << endl;
			}
		}
	}

	int counter = 0; 
	for (auto p2: second) {
		int h = p2.first, w = p2.second;

		if (h == -1 && w == -1) continue;

		for (int i = h; i < H; ++i) {
			if (plate[i][w] == ans[2]) {
				counter++;
			}
		}
	}

	cout << counter << endl;
}