#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {	if (a > b) a = b; }

const int INF = 1<<29;

int main() {
	int N, K, W;
	cin >> N >> K >> W;
	vector<long long> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	vector<vector<int>> dp(N+1,  vector<int>(W+1, INF));
	dp[0][0] = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= W; ++j) {
			chmin(dp[i+1][j], dp[i][j]);
			if (j >= a[i]) chmin(dp[i+1][j], dp[i][j-a[i]] + 1);
		}
	}

	if (dp[N][W] <= K) cout << "YES" << endl;
	cout << "NO" << endl;
}