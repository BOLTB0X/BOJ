#include <iostream>

using namespace std;

//��Ŭ���� ȣ����
int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

void solution(void) {
	int N, S;
	int gcd_value = -1;
	cin >> N >> S;

	//�� �Ÿ����� ��� �� �ִ밡 �Ǵ� ��
	while (N--) {
		int a;
		cin >> a;

		int dist = (S > a) ? (S - a) : (a - S);
		if (gcd_value != -1)
			gcd_value = gcd(gcd_value, dist);

		else
			gcd_value = dist;
	}

	cout << gcd_value << '\n';
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