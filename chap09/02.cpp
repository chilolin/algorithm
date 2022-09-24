#include <iostream>
#include <stack>
#include <vector>
using namespace std;

double calc(const string &exp) {
	stack<double> st;
	for (auto c: exp) {
		if (c >= '0' && c <= '9') {
			double add = c - '0';
			st.push(add);
		} else {
			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();

			if (c == '+') st.push(b + a);
			else if (c == '-') st.push(b - a);
			else if (c == '*') st.push(b * a);
			else st.push(b / a);
		}
	}
	return st.top();
}

int main() {
	string exp = "34+12-*";
	cout << calc(exp) << endl;
}
