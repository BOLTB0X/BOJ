#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check[20001];

int main(void) {
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		if (check[m+1000] == false) {
			arr.push_back(m);
			check[m+1000] = true;
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << ' ';
	return 0;
}