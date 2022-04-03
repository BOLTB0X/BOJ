#include <iostream>
#include <vector>

using namespace std;

vector<int> com;

void DFS(int n, vector<int>& lotto, vector<int>& visited, int cur, int level) {
	if (level == 6) {
		for (int& c : com)
			cout << c << ' ';
		cout << '\n';
		return;
	}

	for (int i = cur; i < n; ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		com.push_back(lotto[i]);
		DFS(n, lotto, visited, i + 1, level + 1);
		com.pop_back();
		visited[i] = 0;
	}
	return;
}

void solution(int n, vector<int>& lotto) {
	vector<int> visited(n, 0); // 초기화

	DFS(n, lotto, visited, 0, 0);
	return;
}

int main(void) {
	int n;
	vector<int> lotto;
	
	while (1) {
		cin >> n;

		// 탈출 조건
		if (n == 0)
			break;
		lotto.resize(n, 0);
		com.clear();

		for (int i = 0; i < n; ++i)
			cin >> lotto[i];
		solution(n, lotto);
		cout << '\n';
	}
	return 0;
}
