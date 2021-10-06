#include <iostream>
#include <vector>

using namespace std;

int result;
vector<int> per;

//최대
int max(int a, int b) {
	return a > b ? a : b;
}

//절대
int abs(int a) {
	return a < 0 ? -a : a;
}

//깊이 우선
void DFS(int* arr, bool* visited, int n, int depth) {
	if (depth == n) {
		int tmp_tot = 0;
		for (int i = 0; i < n-1; ++i) {
			tmp_tot += abs(per[i] - per[i + 1]);
		}
		result = max(result, tmp_tot);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;
		per.push_back(arr[i]);
		visited[i] = true;
		DFS(arr, visited, n, depth + 1);
		visited[i] = false;
		per.pop_back();
	}
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	//동적할당
	int* arr = new int[n];
	bool* visited = new bool[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		visited[i] = false;
	}
	result = -1;
	// 이 순서를 순열을 이용하여 풀 수 있음
	DFS(arr, visited, n, 0);

	cout << result << '\n';
	delete[] arr;
	delete[] visited;

	return 0;
}