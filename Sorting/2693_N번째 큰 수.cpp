#include <iostream>
#include <algorithm>

using namespace std;

void solution(int T) {
	while (T--) {
		int arr[10];
		for (int i = 0; i < 10; ++i)
			cin >> arr[i];
		
		// �������� ����
		sort(arr, arr + 10);
		cout << arr[7] << '\n';
	}
	return;
}

int main(void) {
	int T;

	cin >> T;

	solution(T);
	return 0;
}