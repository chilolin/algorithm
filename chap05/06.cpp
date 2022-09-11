#include <iostream>
#include <vector>
using namespace std;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

const int INF = 1 << 29;

int main() {
	int N, W;
	cin >> N >> W;
	vector<int> a(N), m(N);
	for (int i = 0; i < N; ++i) cin >> a[i] >> m[i];

	vector<vector<int>> dp(N+1, vector<int>(W+1, INF));

	dp[0][0] = true;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= W; ++j) {
			if (dp[i][j] < INF) dp[i+1][j] = 0;

			if (j >= a[i] && dp[i+1][j-a[i]] < m[i])
			{
				chmin(dp[i+1][j], dp[i+1][j-a[i]]+1);
			};
		}
	}

	if (dp[N][W]) cout << 'YES' << endl;
	else cout << 'NO' << endl;
}