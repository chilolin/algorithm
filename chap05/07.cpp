#include <iostream>
#include <vector>
using namespace std;
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

const int INF = 1 << 29;

int main() {
	string S, T;
	cin >> S >> T;

	vector<vector<string>> dp(S.size()+1, vector<string>(T.size()+1, ""));

	dp[0][0] = "";

	for (int i = 0; i < S.size(); ++i) {
		for (int j = 0; j <= T.size(); ++j) {
			if (j == 0) dp[i+1][j] = dp[i][j] + S.at(i);
			else dp[i+1][j] = dp[i][j] + T.at(j-1);
		}
	}

	if (dp[N][W]) cout << 'YES' << endl;
	else cout << 'NO' << endl;
}