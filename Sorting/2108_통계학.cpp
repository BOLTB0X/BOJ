#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int arr[500001];
int tmp_arr[8001];

int find_mode(int tmp_arr[]) {
	int ret;
	int max_value = tmp_arr[0];

	for (int i = 1; i < 8001; i++) {
		if (tmp_arr[i] > max_value) {
			max_value = tmp_arr[i];
			ret = i;
		}
	}
	for (int i = ret + 1; i < 8001; i++) {
		if (tmp_arr[i] == max_value) {
			ret = i;
			break;
		}
	}
	return ret;
}

int main(void) {
	cin >> n;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		tot += arr[i];
		tmp_arr[arr[i] + 4000]++; //ÃÖºó°ª
	}

	sort(arr, arr + n);

	cout << round(double(tot) / n) << '\n';
	cout << arr[(n - 1) / 2] << '\n';
	cout << find_mode(tmp_arr) - 4000 << '\n';
	cout << arr[n - 1] - arr[0] << '\n';

	return 0;
}