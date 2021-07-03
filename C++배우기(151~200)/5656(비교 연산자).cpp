#include <iostream>
#include <string>
using namespace std;

int idx = 1;

int main() {
	while (true) {
		int a, b;
		string s;
		cin >> a >> s >> b;
		if (s == "E") break;
		else if (s == "!=") {
			string text= (a != b) ? "true" : "false";
			cout << "Case " << idx << ": " << text << endl;
		}
		else if (s == ">=") {
			string text = (a >= b) ? "true" : "false";
			cout << "Case " << idx << ": " << text << endl;
		}
		else if (s == "<=") {
			string text = (a <= b) ? "true" : "false";
			cout << "Case " << idx << ": " << text << endl;
		}
		else if (s == "==") {
			string text = (a == b) ? "true" : "false";
			cout << "Case " << idx << ": " << text << endl;
		}
		else if (s == ">") {
			string text = (a > b) ? "true" : "false";
			cout << "Case " << idx << ": " << text << endl;
		}
		else if (s == "<") {
			string text = (a < b) ? "true" : "false";
			cout << "Case " << idx << ": " << text << endl;
		}
		idx++;
	}
	return 0;
}