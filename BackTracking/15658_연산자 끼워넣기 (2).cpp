#include <iostream>
using namespace std;

int n;
int arr[11];
int add, sub, mul, di;
int max_value = -1000000000;
int min_value = 1000000000;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

void DFS(int tot, int idx,int add, int sub, int mul, int di) {
	if (idx == n) {
		max_value = max(max_value, tot);
		min_value = min(min_value, tot);
		return;
	}
	else {
		if (add > 0) 
			DFS(tot + arr[idx], idx + 1, add - 1, sub, mul, di);
		
		if (sub > 0) 
			DFS(tot - arr[idx], idx + 1, add, sub-1, mul, di);
		
		if (mul > 0) 
			DFS(tot * arr[idx], idx + 1, add, sub, mul-1, di);
		
		if (di > 0) 
			DFS((int)tot / arr[idx], idx + 1, add, sub, mul, di-1);
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> add >> sub >> mul >> di;
	DFS(arr[0], 1, add, sub, mul, di);
	
	cout << max_value << '\n';
	cout << min_value << '\n';
	return 0;
}