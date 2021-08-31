#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int BinarySearch(int *arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		// 찾은 경우 중간점 인덱스 반환
		if (arr[mid] == target)
			return 1;
		// 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
		else if (arr[mid] > target)
			end = mid - 1;
		// 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
		else
			start = mid + 1;
	}
	//못찾은 경우
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