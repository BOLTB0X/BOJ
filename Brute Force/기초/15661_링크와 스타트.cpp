#include <iostream>
#include <vector>

using namespace std;

int result = 0x7fffffff; // �ּҸ� ����
int board[21][21];
vector<int> visited;

// �ּڰ� ��ȯ
int Min(int a, int b) {
	return a < b ? a : b;
}

// ���� ��ȯ
int Abs(int a) {
	return a < 0 ? -a : a;
}

// ��Ʈ��ŷ���� ����
void DFS(int n, int cur, int level, int div) {
	if (div == level) {
		int s_score = 0; // ��ŸƮ ��
		int l_score = 0; // ��ũ ��

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (visited[i] && visited[j])
					s_score += board[i][j];
				else if (visited[i] == 0 && visited[j] == 0)
					l_score += board[i][j];
			}
		}

		result = Min(result, Abs(s_score - l_score));
		return;

	}

	for (int i = cur; i <= n; ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		DFS(n, i + 1, level + 1, div);
		visited[i] = 0;
	}
	return;
}

int solution(int n) {
	int answer = 0;
	visited.resize(n + 1, 0);

	// DFS�� ����
	for (int i = 2; i < n - 1; ++i) {
		visited = vector<int>(n + 1, 0); // �ʱ�ȭ
		DFS(n, 1, 0, i);
	}

	answer = result;
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cin >> board[i][j];
	}

	int ret = solution(n);
	cout << ret;
	return 0;
}