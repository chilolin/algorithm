#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> memo;

bool rec(long long w, long long i, const vector<int> &a) {
	if (i == 0) {
		if (w == 0) return true;
		else return false;
	}

	if (memo[i][w]) return true;

	if (rec(w - a[i], i - 1, a)) {
		return memo[i][w] = true;
	}

	if (rec(w, i - 1, a)) {
		return memo[i][w] = true;
	}

		return memo[i][w] = false;
}

int main() {
	int N, W;
	cin >> N >> W;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	memo.assign(N+1, vector<bool>(W+1, false));

	if (rec(W, N, a)) cout << "Yes" << endl;
	else cout << "No" << endl;
}