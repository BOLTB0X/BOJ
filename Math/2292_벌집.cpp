#include <iostream>
#define LL long long

using namespace std;

LL solution(LL n) {
	LL answer = 1;
	LL plus_num = 1;

	// 6�� ����� Ŀ��
	// 6, 12, 18... ����
	while (n > plus_num) {
		plus_num += (6 * answer);
		answer++;
	}

	return answer;
}

int main(void) {
	LL n;

	cin >> n;

	LL ret = solution(n);
	cout << ret;
	return 0;
}