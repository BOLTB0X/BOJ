#include <iostream>
using namespace std;
int arr[10001] = {0};
int n, m;

int solution() {
	cin >> n >> m;
	int start= 0, end = 0; // ���� , ��
	int partial_sum = 0, cnt = 0; //�հ� Ƚ��
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	while (end<=n) { //end�� �迭�� ���̸� ������� ������
		if (partial_sum >= m)
			partial_sum -= arr[start++]; //�κ� ���� Ÿ��m���� ũ�� arr�� ó������ ���ش�.
		else if (partial_sum < m)
			partial_sum += arr[end++]; //�κ� ���� Ÿ��m���� ������� arr�� end�� ������Ű�� �����ش�.
		if (partial_sum == m) cnt++; //�κ� ���� Ÿ�� m�� �����ϸ� cnt 1����
	}
	return cnt; //�� Ƚ���� ��ȯ
}

int main() {
	cout << solution() << '\n';
	return 0;
}