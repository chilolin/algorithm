#include <iostream>
#include <vector>
using namespace std;

using pll = pair<long long, long long>;

int main() {
	int N;
	cin >> N;
	vector<pll> task(N);
	for (int i = 0; i < N; ++i) cin >> task[i].first >> task[i].second;

	sort(task.begin(), task.end(), [&](pll a, pll b) {return a.second < b.second;});

	bool ok = true;
	int current_end_time = 0;
	for (int i = 0; i < N; ++i) {
		current_end_time += task[i].first;
		if (current_end_time > task[i].second) ok = false;
	}

	if (ok) cout << 'Yes' << endl;
	else cout << 'No' << endl;
}