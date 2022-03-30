#include <iostream>
#define LL long long

using namespace std;

int arr[50];

LL solution(int n) {
	LL answer = 0;
	LL max_value = -1;
	LL min_value = 1000001;

	for (int i = 0; i < n; ++i) {
		if (max_value < arr[i])
			max_value = arr[i];
		if (min_value > arr[i])
			min_value = arr[i];
	}
	answer = max_value * min_value;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	LL ret = solution(n);
	cout << ret;
	return 0;
}