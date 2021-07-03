#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	s.clear();
	int cnt1 = 0, cnt2 = 0;

	cin >> s;
	for (int i = 0; i < s.length()-2; i++) {
		if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I')
			cnt1++;
		else if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
			cnt2++;
	}

	cout << cnt1 << endl;
	cout << cnt2 << endl;

	return 0;
}