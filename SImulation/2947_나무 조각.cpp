#include<iostream>

using namespace std;

bool check(int arr[]) {
	for (int i = 0; i < 4; ++i) {
		if (arr[i] + 1 != arr[i + 1])
			return 0;
	}
	return 1;
}

void print_arr(int arr[]) {
	for (int i = 0; i < 5; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
	return;
}

void solution(int arr[]) {
	while (1) {
		// Å»Ãâ Á¶°Ç
		if (check(arr))
			break;
		// ½Ã¹Ä
		else {
			for (int i = 0; i < 4; ++i) {
				if (arr[i] > arr[i + 1]) {
					swap(arr[i], arr[i + 1]);
					print_arr(arr);
				}
			}
		}
	}
	return;
}

int main(void) {
	int arr[5];

	for (int i = 0; i < 5; ++i)
		cin >> arr[i];

	solution(arr);
	return 0;
}