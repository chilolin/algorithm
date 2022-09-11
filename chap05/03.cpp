#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, W;
	cin >> N >> W;
	vector<long long> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));
	dp[0][0] = true;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= W; ++j) {
			if (dp[i][j]) dp[i+1][j] = true;
			if (j >= a[i] && dp[i][j - a[i]]) dp[i+1][j] = true;
		}
	}

	int counter = 0;
	for (int j = 1; j <= W; ++j) {
		if (dp[N][j]) ++counter;
	}
	cout << counter << endl;
}