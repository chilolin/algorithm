#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	int worst_value = INF;
	int second_value = INF;
	for (int i = 2; i < N; i++) {
		if (a[i] < worst_value) {
			second_value = worst_value;
			worst_value = a[i];
		} else if (a[i] < second_value) second_value = a[i];
	}
	
	cout << second_value << endl;
}