#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int rec(int n) {

	if (memo[n] != -1) return memo[n];

	cout << n << endl;
	
	if (n == 0 || n == 1) return 0;

	if (n == 2) return 1;
	

	return memo[n] = rec(n - 1) + rec(n - 2) + rec(n - 3);
}

int main() {
	int N;
	cin >> N;

	memo.assign(N + 1, -1);

	cout << rec(N) << endl;
}