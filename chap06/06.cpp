#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	auto func = [&](double t) -> double {
			return A * t + B * sin(C * PI * t);
	};

	int left = 0, right = 200;
	for (int i = 0; i < 100; ++i) {
		int t = (left + right) / 2;

		if (func(t) <= 100) left = t;
		else right = t;
	}    
	cout << fixed << setprecision(15) << left << endl;
}