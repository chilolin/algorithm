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
		for (int j = 0; j <= W; ++j) {
			if (dp[i][j]) dp[i+1][j] = 0;
			if (j <= a[i] && dp[i+1][j - a[i]]) dp[i+1][j] = true;
		}
	}

	if (dp[N][W]) cout << 'YES' << endl;
	else cout << 'NO' << endl;
}