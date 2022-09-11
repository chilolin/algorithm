#include <iostream>
using namespace std;

int tribo(int N) {
	if (N == 0) return 0;
	else if (N == 1) return 0;
	else if (N == 2) return 1;

	return tribo(N-1) + tribo(N-2) + tribo(N-3);
}

int main() {
	int N;
	cin >> N;
	cout << tribo(N) << endl;
}