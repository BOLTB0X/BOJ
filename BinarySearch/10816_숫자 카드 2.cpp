#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 찾고자 하는 값 이상이 처음 나타나는 위치
int lower_binary(int* arr, int target, int start, int end) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] >= target)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}
// 찾고자 하는 값보다 큰 값이 처음으로 나타나는 위치
int upper_binary(int* arr, int target, int start, int end) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] > target)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	int* n_arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> n_arr[i];
	}
	//n_arr 오름차순으로 정렬
	sort(n_arr, n_arr + n);
	cin >> m;
	int* m_arr = new int[m];
	int* result = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> m_arr[i];
		result[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int lower = lower_binary(n_arr, m_arr[i], 0, n - 1);
		int upper = upper_binary(n_arr, m_arr[i], 0, n - 1);

		if (upper == n - 1 && n_arr[n - 1] == m_arr[i])
			upper++;
		result[i] = upper - lower;
	}
	//정답 출력
	for (int i = 0; i < m; i++) {
		cout << result[i] << ' ';
	}
	cout << '\n';

	return 0;
}