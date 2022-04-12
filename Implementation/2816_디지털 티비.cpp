#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, string channel[]) {
	string answer = "";
	int idx1 = -1, idx2 = -1;

	// ¿Œµ¶Ω∫ √£±‚
	for (int i = 0; i < n;++i) {
		if (channel[i] == "KBS1")
			idx1 = i;
		else if (channel[i] == "KBS2")
			idx2 = i;
	}

	if (idx1 > idx2)
		idx2++;

	for (int i = 0; i < idx1; ++i)
		answer += '1';
	for (int i = 0; i < idx1; ++i)
		answer += '4';

	if (idx2 != 1) {
		for (int i = 0; i < idx2; ++i)
			answer += '1';
		for (int i = 0; i < idx2 - 1; ++i)
			answer += '4';
	}

	return answer;
}

int main(void) {
	int n;
	string channel[100];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> channel[i];

	string ret = solution(n, channel);
	cout << ret;
	return 0;
}