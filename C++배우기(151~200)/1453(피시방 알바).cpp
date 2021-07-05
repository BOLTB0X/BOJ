#include <iostream>
using namespace std;

int main(void) {
	int n;
	int arr[101] = { 0, };
	int occur[101] = { 0, };
	int answer = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		occur[arr[i]] += 1;
	}

	for (int i = 0; i < n; i++) {
		if (occur[arr[i]] > 1) answer += 1;
	}

	cout << answer << '\n';
	return 0;
}