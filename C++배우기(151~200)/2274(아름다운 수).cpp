#include <iostream>
#include <string>
#include <set>
using namespace std;

int t;
string s;

int main() {
	cin >> t;
	while (t!=0) {
		cin >> s;
		set<char> set;
		for (int i = 0; i < s.length(); i++) {
			set.insert(s[i]);
		}
		cout << set.size() << '\n';
		t -= 1;
	}
}