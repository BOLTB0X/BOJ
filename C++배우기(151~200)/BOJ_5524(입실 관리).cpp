#include <iostream>
#include <string>
using namespace std;

int t;
string s;

int main(void) {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			s[j] = tolower(s[j]);
		}
		cout << s << '\n';
	}
	return 0;
}