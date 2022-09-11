#include <iostream>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;

	int counter = 0;
	for (int X = 0; X <= min(K, N); ++X)
	{
		for (int Y = 0; Y <= min(K, N); ++Y)
		{
			int Z = N - X - Y;
			if (0 <= Z && Z <= K) counter++;
		}
	}
	cout << counter << endl;
}