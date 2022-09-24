#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool parse(const string &exp) {
	stack<int> st;
	vector<pair<int, int>> ps;

	for (int i = 0; i < (int)exp.size(); ++i) {
		if (exp[i] == '(') {
			st.push(i);
		} else {
			if (st.empty()) {
				cout << "error" << endl;
				return false;
			}; 
			int a = st.top();
			st.pop();
			ps.push_back({a, i});
		}
	}
	if (!st.empty()) {
		cout << "too many" << endl;
		return false;
	};	
	
	sort(ps.begin(), ps.end());
	for (int i = 0; i < (int)ps.size(); ++i) {
		if (i) cout << ", ";
		cout << "(" << ps[i].first << ", " << ps[i].second << ")";
	}
	cout << endl;
	return true;
}

int main() {
	string exp = "((()())())";
	parse(exp);
}