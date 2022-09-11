#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo;

bool func(int i, int w, const vector<int> &a) {
	if (i == 0)
	{
		if (w == 0) return true;
		else return false;
	};

	if (memo[i][w] != -1) return memo[i][w];

	if (func(i-1, w-a[i-1], a)) return memo[i][w] = 1;

	if (func(i-1, w, a)) return memo[i][w] = 1;

	return memo[i][w] = 0;
}

int main() {
	int N, W;
	cin >> N >> W;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	memo.assign(N+1, vector<int>(W+1, -1));
	cout << func(N, W, a) << endl;
}