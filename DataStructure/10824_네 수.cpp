#include <iostream>
#include <string>

using namespace std;

void solution(void) {
	int a, b, c, d;
	string st1, st2;
	cin >> a >> b >> c >> d;

	//���ڿ� ���� �Լ��� �̿�
	st1 = to_string(a) + to_string(b);
	st2 = to_string(c) + to_string(d);
	long long tot = stoll(st1) + stoll(st2);

	cout << tot << '\n';
	return;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}