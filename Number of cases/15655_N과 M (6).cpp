#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> com;
vector<bool> visited;

//깊이우선탐색
void DFS(vector<int>& arr, int n, int m, int cur, int depth) {
	//탈출조건
	if (com.size() == m) {
		for (int i = 0; i < com.size(); ++i)
			cout << com[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = cur; i < arr.size(); ++i) {
		if (visited[i])
			continue;
		com.push_back(arr[i]);
		visited[i] = true;
		//호출
		DFS(arr, n, m, i + 1, depth + 1);
		com.pop_back();
		visited[i] = false;
	}
	return;
}

void solution(void) {
	int n, m;

	//입력
	cin >> n >> m;

	//벡터 사이즈 설정
	vector<int> arr(n);
	visited.resize(n, false);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	//오름차순
	sort(arr.begin(), arr.end());

	//탐색 시작
	DFS(arr, n, m, 0, 0);
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