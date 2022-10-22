#include <iostream>
#include <vector>
using namespace std;

int times(int n) {
	int exp = 0;
	while (n % 2 == 0) n /= 2, ++exp;
	return exp;
}

int main() {
	int N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) cin >> a[i];

	int res = 1234567890;
	for (int i = 0; i < N; ++i) {
		res = min(res, times(a[i]));
	}

	cout << res << endl;
}