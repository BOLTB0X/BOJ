#include <iostream>
#include <vector>

using namespace std;

int result = -1;
vector<int> per;

//최대값 비교
int max(int a, int b) {
	return a > b ? a : b;
}

//절댓값 반환
int abs(int a) {
	if (a < 0)
		return -a;
	return a;
}

//차이값 반환
int get_target(vector<int>& per, int n) {
	int tot = 0;
	for (int i = 0; i < n-1; i++) {
		tot += abs(per[i] - per[i + 1]);
	}
	return tot;
}

//깊이 우선 탐색
void DFS(int* arr, bool* visited, int n, int depth) {
	if (depth == n) {
		result = max(result, get_target(per,n));
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		per.push_back(arr[i]);
		visited[i] = true;
		DFS(arr, visited, n, depth + 1);
		per.pop_back();
		visited[i] = false;
	}
}

//해결
void solution(void) {
	int n;
	cin >> n;

	//메모리 생성
	int* arr = new int[n];
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		visited[i] = false;
	}

	DFS(arr, visited, n, 0);
	cout << result << '\n';

	//메모리 해제
	delete[] arr;
	delete[] visited;
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