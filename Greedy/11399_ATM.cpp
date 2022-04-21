#include <iostream>

using namespace std;

void merge(int n, int* arr, int start, int end) {
	int mid = (start + end) / 2;
	int* sorted = new int[n];
	int i = start, j = mid + 1, k = start;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid) {
		for (int a = j; a <= end; ++a)
			sorted[k++] = arr[a];
	}
	else {
		for (int a = i; a <= mid; ++a)
			sorted[k++] = arr[a];
	}

	for (int a = start; a <= end; ++a)
		arr[a] = sorted[a];

	delete[] sorted;
	return;
}

// 병합정렬
void merge_Sort(int n, int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_Sort(n, arr, start, mid);
		merge_Sort(n, arr, mid + 1, end);
		merge(n, arr, start, end);
	}

	return;
}

int solution(int n, int* arr) {
	int answer = 0;

	merge_Sort(n, arr, 0, n - 1); // 오름차순 정렬
	
	// 그리디
	for (int i = 0; i < n; ++i) {
		int tot = 0;
		for (int j = i; j >= 0; --j) 
			tot += arr[j]; // 누적합
		answer += tot;
	}

	return answer;
}

int main(void) {
	int n;
	int* arr;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = solution(n, arr);
	cout << ret;
	delete[] arr;
	return 0;
}
