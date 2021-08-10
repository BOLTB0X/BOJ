#include <iostream>
using namespace std;

int n;
int arr[1001];
void swap(int* a, int* b) {
	int* tmp = a;
	a = b;
	b = tmp;
}

//�������� �̿�
void solution(int n, int *arr) {
	for (int i = 0; i < n; i++) {
		int min_idx = i; //�ּҰ� ����
		for (int j = i; j < n; j++) {
			// �� ���� ���� ã�´ٸ�
			if (arr[j] < arr[min_idx])
				min_idx = j; //��ü
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