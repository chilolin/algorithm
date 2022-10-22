#include <iostream>
#include <vector>
using namespace std;

void rec(long long K, long long cur, int bit, long long &counter) {
	if (cur > K) return;
	if (bit == 0b111) ++counter;

	rec(K, cur * 10 + 3, bit | 0b001, counter);
	rec(K, cur * 10 + 5, bit | 0b010, counter);
	rec(K, cur * 10 + 7, bit | 0b100, counter);
}

int main() {
	int K;
	cin >> K;

	long long counter = 0;
	rec(K, 0, 0, counter);

	cout << counter << endl;
}