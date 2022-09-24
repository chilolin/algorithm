#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i) cin >> a[i] >> b[i];

	unordered_map<int, int> B(N);
	for (int i = 0; i < N; ++i) {
		if (B.find(b[i]) == B.end()) B[b[i]] = 1;
		else B[b[i]]++;
	}

	int ok = false;
	for (int i = 0; i < N; ++i) {
		if (B.find(K - a[i]) == B.end()) continue;
		ok = true;
	}

	cout << ok << endl;
}