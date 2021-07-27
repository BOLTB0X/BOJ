#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n,k;
int arr[1001] = { 0 };

int solution() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		string s = to_string(n*i);
		reverse(s.begin(), s.end());
		arr[i]=stoi(s);
	}
	int max_value = arr[1];
	for (int i = 2; i <= k; i++) {
		if (arr[i] > max_value)
			max_value = arr[i];
	}

	return max_value;
}

int main(void) {
	int result = solution();
	cout << result << endl;

	return 0;
}