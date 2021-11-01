#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> per;

//깊이우선탐색
void DFS(vector<int>& arr, int n, int m, int depth) {
	//탈출조건
	if (per.size() == m) {
		for (int i = 0; i < per.size(); ++i)
			cout << per[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); ++i) {
		per.push_back(arr[i]);
		DFS(arr, n, m, depth + 1);
		per.pop_back();
	}
	return;
}

void solution(void) {
	int n, m;

	//입력
	cin >> n >> m;

	//벡터 사이즈 설정
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	//오름차순
	sort(arr.begin(), arr.end());

	//탐색 시작
	DFS(arr, n, m, 0);
	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}