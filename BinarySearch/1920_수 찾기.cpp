#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int BinarySearch(int *arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		// ã�� ��� �߰��� �ε��� ��ȯ
		if (arr[mid] == target)
			return 1;
		// �߰����� ������ ã���� �ϴ� ���� ���� ��� ���� Ȯ��
		else if (arr[mid] > target)
			end = mid - 1;
		// �߰����� ������ ã���� �ϴ� ���� ū ��� ������ Ȯ��
		else
			start = mid + 1;
	}
	//��ã�� ���
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	sort(arr, arr + n);
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		int ret = BinarySearch(arr, target, 0, n-1);
		cout << ret << '\n';
	}
	return 0;
}