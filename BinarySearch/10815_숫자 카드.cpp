#include <iostream>
#include <algorithm>
using namespace std;

int n_arr[500001];
int m_arr[500001];
int result[500001];

bool binary_search(int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (n_arr[mid] == target)
			return true;
		else if (n_arr[mid] > target)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> n_arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> m_arr[i];
		result[i] = 0;
	}
	//n_arr 오름차순정렬
	sort(n_arr, n_arr + n);
	for (int i = 0; i < m; i++) {
		bool check = binary_search(m_arr[i], 0, n - 1);
		if (check)
			result[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		cout << result[i] << ' ';
	}
	cout << '\n';
	return 0;
}