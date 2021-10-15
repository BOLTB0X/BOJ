#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1000001];
int arr2[1000001];

void merge(int left, int right) {
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) {
		arr2[k++] = arr[tmp++];
	}
	for (int l = left; l <= right; l++)
		arr[l] = arr2[l];
}

void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid); //분할
		merge_sort(mid + 1, right); //분할
		merge(left, right); //정복
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	merge_sort(0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}