#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ++i) {
		s[i] = s[i] - 3;
		if (s[i] < int('A')) {
			s[i] += 26;
		}
		cout << s[i];
	}
	return 0;
}