#include <iostream>
using namespace std;

int solution(int* arr, int arr_len, long long target) {
	int start = 0;
	int end = 0;
	int partial_tot = 0, cnt = 0;
	
	//�� ������ �˰���
	//�� end�� �迭�� ���̸� ������� ������
	while (end<=arr_len) {
		//�κ����� Ÿ�ٰ� �������ٸ�
		if (partial_tot == target)
			cnt++;
		//�κ� ���� Ÿ��m���� ������� arr�� end��
		if (partial_tot < target)
			partial_tot += arr[end++];
		//�κ� ���� Ÿ��m���� ũ�� arr�� ó������
		else if (partial_tot >= target)
			partial_tot -= arr[start++];
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long m;
	int arr[10001];
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ret = solution(arr, n, m);
	cout << ret << '\n';
	return 0;
}