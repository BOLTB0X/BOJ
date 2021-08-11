#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void solution() {
	cin >> n;
	vector<vector<int>> arr(n,vector<int>(2,0));
	for (int i = 0; i < n; i++) 
		cin >> arr[i][0] >> arr[i][1];
	
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		cout << arr[i][0] << ' ' << arr[i][1] << '\n';
	}
}

int main() {
	solution();
	return 0;
}