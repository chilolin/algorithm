#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {	if (a < b) a = b; }

int main() {
	int N;
	cin >> N;
	vector<vector<long long>> a(N, vector<long long>(3));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];

	vector<vector<long long>> dp(N+1, vector<long long>(3, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (j == k) continue;
				chmax(dp[i+1][k], dp[i][j] + a[i][k]);
			}
		}
	}

	long long res = 0;
	for (int i = 0; i < 3; ++i) chmax(res, a[N][i]);
	cout << res << endl;
}