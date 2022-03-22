#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	int joi = 0, ioi = 0;

	cin >> str;
	
	for (int i = 0; i < str.length() - 2; ++i) {
		string s = str.substr(i, 3); // 문자열 자르기

		if (s == "JOI")
			joi++;

		else if (s == "IOI")
			ioi++;
	}

	cout << joi << '\n' << ioi;
	return 0;
}