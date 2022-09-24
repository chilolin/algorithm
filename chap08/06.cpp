#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> a(N), b(M);
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < M; ++i) cin >> b[i];

	unordered_map<int, int> A(N);
	for (int i = 0; i < N; ++i) {
		if (A[a[i]] == NULL) A[a[i]] = 1;
		else A[a[i]]++;
	}

	int counter = 0;
	for (int i = 0; i < M; ++i) {
		if (A[b[i]] == NULL) return;
		counter += A[b[i]];
	}

	cout << counter << endl;
}