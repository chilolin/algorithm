#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int cast(string S) {
	int n = S.size();

	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += (S[n - i - 1] - '0') * pow(10, i);
	}

	return res;
}

int main() {
	string S;
	cin >> S;

	int N = S.size();
	
	int res = 0;
	for (int bit = 0; bit < (1 << (N-1)); ++bit) {
		int start = 0;
		for (int i = 0; i < N; ++i) {
			if (bit & (1 << i)) {
				cout << "slice1: " << S.substr(start, i + 1 - start) << endl;
				res += cast(S.substr(start, i + 1 - start));
				start = i + 1;
			}
		}
		if (start == N) continue;
		cout << "slice2: " << S.substr(start, N - start) << endl;
		res += cast(S.substr(start, N - start));
	}

	cout << res << endl;
}


