#include <iostream>
using namespace std;

int n,m;
int arr[100000];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(int start, int end) {
	//원소가 한개인 경우
	if (start >= end)
		return;
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		//피벗보다 큰 데이터를 찾을 때까지 반복
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		//피버소다 작은 데이터를 찾을 떄까지 반복
		while (right > start && arr[right] >= arr[pivot])
			right--;
		//엇갈렷다면
		if (left > right) {
			//교체 작은 데이터와 교체
			swap(arr[pivot], arr[right]);
		}
		else {
			//큰데이터와 작은 데이터 교체
			swap(arr[left], arr[right]);
		}
	}
	quick_sort(start, right - 1);
	quick_sort(right + 1, end);
}

bool binary_search(int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;

		//찾은 경우
		if (arr[mid] == target)
			return true;
		//타겟이 작다면 첫~중간으로 범위를 줄임
		else if (arr[mid] > target) {
			end = mid - 1;
		}
		//타겟이 크다면 중간~끝으로 범위를 줄임
		else if (arr[mid] < target) {
			start = mid + 1;
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	quick_sort(0,n-1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int value;
		cin >> value;
		cout << binary_search(value, 0, n - 1) << '\n';
	}
	return 0;
}
