#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<char> op;
vector<int> visited(10, 0);
vector<string> result;

int check(string seq) {
	for (int i = 0; i < k; ++i) {
		if (op[i] == '>') {
			if (seq[i] < seq[i + 1])
				return 0;
		}
		else if (op[i] == '<')
			if (seq[i] > seq[i + 1])
				return 0;
	}
	return 1;
}

void DFS(string seq, int level) {
	if (level == (k + 1)) {
		if (check(seq) == 1)
			result.push_back(seq);
		return;
	}

	for (int i = 0; i <= 9; ++i) {
		// 중복방지
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		DFS(seq + to_string(i), level + 1);
		visited[i] = 0;
		
	}
	return;
}

void solution(void) {
	DFS("", 0);
	sort(result.begin(), result.end());

	return;
}

int main(void) {
	cin >> k;
	op.resize(k, 0);
	for (int i = 0; i < k; ++i)
		cin >> op[i];

	solution();
	cout << result[result.size() - 1] << '\n' << result[0];
	return 0;
}