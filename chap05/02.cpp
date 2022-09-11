#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));

	for (int i = 0; i < N; ++i) {
		for (int w = 0; w <= W; ++w) {
			if (dp[i][w]) dp[i+1][w] = true;
			if (w >= a[i] && dp[i][w - a[i]]) dp[i+1][w] = true;
		}
	}

	if (dp[N][W]) cout << "YES" << endl;
	cout << "NO" << endl;
}