#include <iostream>

using namespace std;

// 소수 판별
int is_Prime(int number) {
	if (number == 0 || number == 1)
		return 0;

	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0)
			return 0;
	}
	return 1;
}

int main(void) {
	int n, cnt = 0;
	int arr[101];
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (is_Prime(arr[i]) == 1)
			cnt++;
	}

	cout << cnt;
	return 0;
}