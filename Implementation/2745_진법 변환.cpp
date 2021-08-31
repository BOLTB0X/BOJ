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

int solution(string n, int b) {
	int answer = 0;

	int cnt = 0;
	for (int i = n.length() - 1; i >= 0; i--) {
		int tmp = n[i];
		if (tmp >= 'A' && tmp <= 'Z')
			answer += (tmp - 'A' + 10) * ((int)pow(b, cnt));
		else
			answer += (tmp - '0') * ((int)pow(b, cnt));
		cnt++;
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n;
	int b;
	cin >> n >> b;
	cout << solution(n, b) << '\n';
	return 0;
}