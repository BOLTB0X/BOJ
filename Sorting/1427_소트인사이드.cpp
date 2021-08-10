#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void swap(int* a, int* b) {
	int *tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	string nums;

	cin >> nums;
	int num_len = nums.length();
	int* arr = new int[num_len];

	for (int i = 0; i < num_len; i++) {
		arr[i] = nums[i] - '0';
	}

	for (int i = 0; i < num_len; i++) {
		int max_idx = i;
		for (int j = i; j < num_len; j++) {
			if (arr[max_idx] < arr[j])
				max_idx = j;
		}
		swap(arr[max_idx], arr[i]);
	}

	for (int i = 0; i < num_len; i++) {
		cout << arr[i];
	}
	cout << '\n';
	return 0;
}