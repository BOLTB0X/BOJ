#include <iostream>

using namespace std;

void solution(void) {
	int n;
	cin >> n;

	long long result = 0;

	//  100���� 11�� ����� 
	// -> 11,22,33,44,55,66,77,88,99 �� 9�� = 100/11
	for (int i = 1; i <= n; ++i)
		result += (n / i) * i;

	cout << result << '\n';
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