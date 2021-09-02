#include <iostream>
#include <algorithm>
using namespace std;

int two_pointer(int* arr, int arr_len, long long target) {
	int start = 0, end = arr_len - 1;
	int partial_tot = 0;
	int cnt = 0;
	//오름차순으로 정렬
	sort(arr, arr + arr_len);
	while (start<end) {
		partial_tot = arr[start] + arr[end];
		if (partial_tot == target) {
			cnt++;
			start++;
			end--;
		}
		else if (partial_tot < target)
			start++;
		else if (partial_tot > target)
			end--;
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long x;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	int ret = two_pointer(arr, n, x);
	cout << ret << '\n';
	delete[] arr;
	return 0;
}