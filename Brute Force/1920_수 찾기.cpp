#include <iostream>
#include <algorithm>
using namespace std;
int n_arr[100001];
int m_arr[100001];

void binary_search(int *arr,int target, int start, int end) {
	int mid;
	while (start <= end) {
		mid = ((start + end) / 2);
		// 찾은 경우 중간점 인덱스 반환
		if (n_arr[mid] == target) {
			cout << 1 << '\n';
			return;
		}
		// 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
		else if (n_arr[mid] > target)
			end = mid - 1;
		// 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
		else
			start = mid + 1;
	}
	cout << 0 << '\n';
	return;
}

int main(void) {
	int n,m;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> n_arr[i];
	}
	cin >> m;
	sort(n_arr, n_arr + n);
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		binary_search(n_arr, tmp, 0, n - 1);
	}
	return 0;
}