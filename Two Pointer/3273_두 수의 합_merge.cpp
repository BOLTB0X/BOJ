#include <iostream>
using namespace std;

int arr[100001];
int tmp[100001];

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	int tmp_idx = i > mid ? j : i;

	while (k <= right) {
		tmp[k++] = arr[tmp_idx++];
	}

	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];
}

void merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);
	}
}

int two_pointer(int arr_len, int target) {
	int start = 0, end = arr_len - 1;
	int partial_tot = 0;
	int cnt = 0;
	//오름차순으로 정렬
	merge_sort(start, end);
	while (start < end) {
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
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	int ret = two_pointer(n, x);
	cout << ret << '\n';
	return 0;
}