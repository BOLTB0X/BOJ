#include <iostream>
#include <algorithm> //sort

using namespace std;

int arr[1000001];

int main(void) {
	int n;
	
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);
	cout << arr[0] << ' ' << arr[n - 1];
	return 0;
}