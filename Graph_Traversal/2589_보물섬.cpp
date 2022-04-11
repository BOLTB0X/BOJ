#include <iostream>
#include <string>
#include <queue>
#define Max_Value 2511

using namespace std;

int n, m;
int result = -1;
char board[51][51];
int visited[51][51];
int dist[51][51];

// �����¿�
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

void init(void) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visited[i][j] = 0;
			dist[i][j] = 0;
		}
	}
	return;
}

// �ʺ�켱Ž��
void BFS(int y, int x) {
	queue<pair<int, int>> que; // ť ����

	visited[y][x] = 1;
	dist[y][x];
	que.push({ y,x });

	// ť�� ��������
	while (!que.empty()) {
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// �����ʰ�
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			// ���̸�
			if (board[ny][nx] == 'W')
				continue;

			// ��湮�� ���
			if (visited[ny][nx] == 1)
				continue;

			visited[ny][nx] = 1;
			dist[ny][nx] = dist[cy][cx] + 1;
			if (result < dist[ny][nx])
				result = dist[ny][nx];
			que.push({ ny,nx });
		}
	}
	return;
}

int solution(void) {
	int answer = 0;

	// ����Ž��
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// ���� �߰�
			if (board[i][j] == 'L') {
				init(); // �Ÿ�����Ʈ �ʱ�ȭ
				BFS(i, j);
			}
		}
	}
	answer = result;
	return answer;
}

int main(void) {
	string tmp;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j)
			board[i][j] = tmp[j];
	}

	int ret = solution();
	cout << ret;

	return 0;
}