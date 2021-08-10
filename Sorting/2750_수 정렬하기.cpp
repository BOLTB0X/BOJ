#include <iostream>
using namespace std;

int n;
int arr[1001];
void swap(int* a, int* b) {
	int* tmp = a;
	a = b;
	b = tmp;
}

//선택정렬 이용
void solution(int n, int *arr) {
	for (int i = 0; i < n; i++) {
		int min_idx = i; //최소값 설정
		for (int j = i; j < n; j++) {
			// 더 작은 값을 찾는다면
			if (arr[j] < arr[min_idx])
				min_idx = j; //교체
		}
		swap(arr[min_idx], arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solution(n, arr);
	return 0;
}