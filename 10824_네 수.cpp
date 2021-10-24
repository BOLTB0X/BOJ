#include <iostream>
#include <string>

using namespace std;

void solution(void) {
	int a, b, c, d;
	string st1, st2;
	cin >> a >> b >> c >> d;

	//문자열 내부 함수들 이용
	st1 = to_string(a) + to_string(b);
	st2 = to_string(c) + to_string(d);
	long long tot = stoll(st1) + stoll(st2);

	cout << tot << '\n';
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}