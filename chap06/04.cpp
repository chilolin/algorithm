#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL<<50;

int main() {
	int N, M;
	cin >> N >> M;
	vector<long long> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	long long left = 0, right = INF;
	while (right - left > 1) {
		long long x = (left + right) / 2;

		int cnt = 1;
		int prev = 0;
		for (int i = 0; i < N; ++i) {
			if (a[i] - a[prev] >= x) {
				++cnt;
				prev = i;
			}
		}

		if (cnt >= M) left = x;
		else right = x;
	}
	cout << left << endl;
}