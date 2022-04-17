#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;
vector<bool> visited;

void DFS(int n, vector<int>& per, int level) {
	if (level == n) {
		result.push_back(per);
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		per.push_back(i);
		DFS(n, per, level + 1);
		per.pop_back();
		visited[i] = 0;
	}
	return;
}

vector<vector<int>> solution(int n) {
	vector<vector<int>> answer;
	visited.resize(n + 1, 0);

	vector<int> per;
	DFS(n, per, 0);
	answer = result;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	vector<vector<int>> ret = solution(n);
	for (auto& r : ret) {
		for (int i = 0; i < n; ++i)
			cout << r[i] << ' ';
		cout << '\n';
	}
	return 0;
}
