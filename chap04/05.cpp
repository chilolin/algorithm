#include <iostream>
#include <string>
using namespace std;

void func(long long K, long long cur, int use, long long &counter) {
	if (K < cur) return;
	if (use == 0b111) ++counter;

	func(K, cur * 10 + 7, use | 0b001, counter);
	func(K, cur * 10 + 5, use | 0b010, counter);
	func(K, cur * 10 + 3, use | 0b100, counter);
}

int main() {
	long long K;
	cin >> K;
	long long counter = 0;
	func(K, 0, 0, counter);
	cout << counter << endl;
}