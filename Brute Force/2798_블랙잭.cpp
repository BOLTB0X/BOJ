#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[101];

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int max_value = -1;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int tot = arr[i] + arr[j] + arr[k];
				if (m >= tot) 
					max_value=max(max_value,tot);
			}
		}
	}
	cout << max_value <<'\n';
	return 0;
}