#include <iostream>
#include <vector>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;

	int res = 0;
	for (int i = 0; i < K + 1; ++i) {
		for (int j = 0; j < K + 1; ++j) {
			int Z = N - i - j;
			if (0 <= Z && Z <= K) res++;
		}
	}

	cout << res << endl;
}