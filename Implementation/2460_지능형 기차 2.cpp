#include <iostream>

using namespace std;

pair<int, int> arr[11];

int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(void) {
	int answer = arr[1].second; // �ʱ� ��
	int cur = arr[1].second; // ����

	for (int i = 2; i <= 10; ++i) {
		cur -= arr[i].first; // ���� ��������� ��
		cur += arr[i].second; // ���� ź ������� ������

		// üũ
		answer = Max(cur, answer);
	}

	return answer;
}

int main(void) {
	for (int i = 1; i <= 10; ++i) {
		// ���� ���, ź ��� 
		cin >> arr[i].first >> arr[i].second;
	}

	int ret = solution();
	cout << ret;

	return 0;
}