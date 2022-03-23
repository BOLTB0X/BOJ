#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[101][101];
int visited[101][101];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

typedef struct {
	int y, x;
} Sol;

// �ʺ�켱Ž��
int BFS(int n, int m, int y, int x) {
	int ret = 1;
	visited[y][x] = 1;
	queue<Sol> que;
	que.push({ y,x });

	while (!que.empty()) {
		Sol cur =que.front();
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			// �����ʰ�
			if (ny < 0 || nx < 0 || ny >= m || nx >= n)
				continue;

			// ��湮 �� ���� ���簡 �ƴϸ�
			if (visited[ny][nx] == 1)
				continue;

			if (board[ny][nx] == board[y][x]) {
				ret++;
				visited[ny][nx] = 1;
				que.push({ ny, nx });
			}
		}
	}

	return ret;
}

pair<int, int> solution(int n, int m) {
	pair<int, int> answer = { 0,0 };

	// �ʱ�ȭ
	for (int i = 0; i < m; ++i)
		memset(visited[i], 0, n);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			// �Ʊ��̸�
			if (board[i][j] == 'W' && visited[i][j] == 0) {
				int ret = BFS(n, m, i, j);
				answer.first += ret * ret;
			}
			// �����̸�
			else if (board[i][j] == 'B' && visited[i][j] == 0) {
				int ret = BFS(n, m, i, j);
				answer.second += ret * ret;
			}
		}
			
	}
	return answer;
}

int main(void) {
	int n, m;
	string tmp;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		for (int j = 0; j < n; ++j)
			board[i][j] = tmp[j];
	}

	pair<int, int> ret = solution(n, m);
	cout << ret.first << ' ' << ret.second;

	return 0;
}