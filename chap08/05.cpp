#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main() {
	int N, M;
	vector<int> a(N), b(M);
	for (int i = 0; i < N; ++i) cin >> a[i];
	for (int i = 0; i < M; ++i) cin >> b[i];

	unordered_set<int> A(a.begin(), a.end());

	int count = 0;
	for (int = 0; i < M; ++i) {
		if (A[b[i]]) ++count;
	}

	cout << count << endl;
}