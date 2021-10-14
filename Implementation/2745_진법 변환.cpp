#include <iostream>
#include <string>

using namespace std;

int pow(int a, int b) {
	int res = 1;
	if (b == 0)
		return 1;
	else {
		for (int i = 0; i < a; i++)
			res *= a;
	}
	return res;
}

int main(void) {
	string N = "";
	int B;
	int answer = 0;

	cin >> N >> B;

	for (int i = N.length() - 1; i >= 0; i--) {
		if (N[i] >= 'A' && N[i] <= 'Z')
			answer += (N[i] - 'A' + 10) * pow(B, N.length() - 1 - i);
		else
			answer += (N[i] - '0') * pow(B, N.length() - 1 - i);
	}
	
	cout << answer << '\n';
	return 0;
}
