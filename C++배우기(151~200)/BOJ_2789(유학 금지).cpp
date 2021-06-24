#include <iostream>
#include <string>
using namespace std;
string st;
string answer;
int main() {
	bool check;
	string c = "CAMBRIDGE";
	cin >> st;
	for (int i = 0; i < st.length(); i++) {
		check = false;
		for (int j = 0; j < 9; j++) {
			if (c[j] == st[i]) {
				check = true;
			}
		}
		if (!check) {
			answer += st[i];
		}
	}
	cout << answer << endl;
}