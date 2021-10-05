#include <iostream>
#include <vector>

using namespace std;

int n, result;
vector<int> per;

//최대
int max(int a, int b) {
	return a > b ? a : b;
}

//절댓값
int abs(int a) {
	return a < 0 ? -a : a;
}

//최대값 찾기
void get_max_value(int* arr, bool* visited) {
	int tot = 0;
	for (int i = 0; i < n - 1; i++) {
		tot += abs(per[i] - per[i + 1]);
	}
	result = max(tot, result);
	return;
}

//깊이 우선으로 완전탐색
void DFS(int* arr, bool* visited, int depth) {
	//입력받은 n만큼 도달했다면
	if (depth == n) {
		get_max_value(arr, visited);
		return;
	}
	//중복순열이 아니므로 재방문은 피함
	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		per.push_back(arr[i]);
		DFS(arr, visited, depth + 1);
		visited[i] = false;
		per.pop_back();
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//입력
	cin >> n;
	
	//동적할당
	int* arr = new int[n];
	bool* visited = new bool[n];
	
	//초기화
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	//초기화
	for (int i = 0; i < n; i++) 
		visited[i] = false;
	
	result = -1;
	DFS(arr, visited, 0);
	cout << result << '\n';
	
	delete[] arr;
	delete[] visited;
	
	return 0;
}